#include "arxidentification.h"


ARXIdentification::ARXIdentification()
{
    ARXIdentification(1, 0, 1, 1);
}

ARXIdentification::ARXIdentification(int n_dB, int n_dA, unsigned int n_k, double n_lambda):
    dB(n_dB),
    dA(n_dA),
    lambda(n_lambda)

{
    std::vector<double> B(dB+1, 0.9);
    std::vector<double> A(dA+1, 0.9);
    md = ModelData(B, A, n_k);
    covarMatrix = boost::numeric::ublas::identity_matrix<double>(dA+dB+1)*1000;

    inQueue = std::deque<double>(dB+1 + n_k, 0);
    outQueue = std::deque<double>(dA + 1, 0);

    theta = boost::numeric::ublas::matrix<double>(dA+dB+1, 1);
    phi = boost::numeric::ublas::matrix<double>(dA+dB+1, 1);

    temp1 = boost::numeric::ublas::matrix<double>(dA+dB+1, 1);
    temp3 = boost::numeric::ublas::matrix<double>(dA+dB+1, dA+dB+1);

    v_K = boost::numeric::ublas::matrix<double>(dA+dB+1, 1);
    n_B = std::vector<double> (dB+1, 1);
    n_A = std::vector<double> (dA+1);
}

ModelData ARXIdentification::identify(double in, double out)
{
    inQueue.push_front(in);
    outQueue.push_front(-out);//minus skraca obliczenia przy podstawianiu do wzoru

    if (inQueue.size() > dB+1 + md.getK()) inQueue.pop_back();
    if (outQueue.size() > dA + 1) outQueue.pop_back();

    l_B = md.getB();
    l_A = md.getA();

    std::copy(l_B.begin(), l_B.end(), theta.begin1());
    std::copy(l_A.begin()+1, l_A.end(), theta.begin1()+dB+1);

    std::copy(inQueue.begin() + md.getK(), inQueue.end(), phi.begin1());
    std::copy(outQueue.begin() + 1, outQueue.end(), phi.begin1()+dB+1);

    double epsilon = out - inner_product(theta.begin1(),theta.end1(),phi.begin1(),0.0);

    temp1 = prod(trans(phi), covarMatrix);
    temp1 = prod(temp1, phi);
    double temp2 = lambda + temp1(0,0);

    temp3 = prod(covarMatrix, phi);
    temp3 = prod(temp3, trans(phi));
    temp3 = prod(temp3, covarMatrix);

    covarMatrix = (covarMatrix - (temp3/temp2))/lambda;

    v_K = prod(covarMatrix, phi);
    theta = theta + v_K*epsilon;

    std::copy(theta.begin1(), theta.begin1()+dB+1, n_B.begin());
    std::copy(theta.begin1()+dB,theta.begin1()+dB+dA+1, n_A.begin());
    n_A[0] = 1;

    md = ModelData(n_B, n_A, md.getK());

    return md;
}

ModelData ARXIdentification::getModel(){
    return md;
}

void ARXIdentification::setModel(ModelData n_md){
    if(n_md.getB().size() == dB+1 && n_md.getA().size() == dA){
        md = n_md;
    }else{
        //do nothing..
    }
}

double ARXIdentification::getLambda(){
    return lambda;
}

void ARXIdentification::setLambda(double n_lambda){
    lambda = n_lambda;
}

void ARXIdentification::reset(){
    std::vector<double> B(dB+1, 1);
    std::vector<double> A(dA+1, 1);
    md.setB(B);
    md.setA(A);
    inQueue.clear();
    outQueue.clear();
    covarMatrix = boost::numeric::ublas::identity_matrix<double>(dA+dB+1)*1000;
    inQueue = std::deque<double>(inQueue.size(), 0);
    outQueue = std::deque<double>(outQueue.size(), 0);
    theta = boost::numeric::ublas::matrix<double>(dA+dB+1, 1);
    phi = boost::numeric::ublas::matrix<double>(dA+dB+1, 1);
    temp1 = boost::numeric::ublas::matrix<double>(dA+dB+1, 1);
    temp3 = boost::numeric::ublas::matrix<double>(dA+dB+1, dA+dB+1);
    v_K = boost::numeric::ublas::matrix<double>(dA+dB+1, 1);
    n_B = std::vector<double> (dB+1, 1);
    n_A = std::vector<double> (dA+1);
}
