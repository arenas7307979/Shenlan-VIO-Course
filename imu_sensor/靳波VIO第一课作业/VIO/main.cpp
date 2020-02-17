#include <QCoreApplication>
#include<iostream>
#include<Eigen/Eigen>
using namespace std;
using namespace Eigen;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Matrix3d R;

    AngleAxisd v(M_PI/4,Vector3d(0,0,1));//��ת����
    R=v.toRotationMatrix();//��ת����תΪ��ת����
    cout<<" Rotation Matrix:"<<endl<<endl;
    cout<<R<<endl;
    cout<<endl;

    Quaterniond q(R);//��ת����ת��Ԫ��
    cout<<" Quaternion:"<<endl<<endl;
    cout<<q.w()<<" "<<q.x()<<" "<<q.y()<<" "<<q.z()<<endl;
    cout<<endl;

    Vector3d w(0.01,0.02,0.03);//��ά�����������Ӧ��ǣ�Ȼ��ʹ���޵����˹��ʽ������ת����
    double angle=pow(w(0)*w(0)+w(1)*w(1)+w(2)*w(2),0.5);//����ά������Ӧ��
    Vector3d axis=w/angle;//����ά������Ӧ��
    Matrix3d detR;//����ת����

    Matrix3d I;
    I.setIdentity();//��λ����
    Matrix3d n;//���Ӧ�ķ��Գƾ���
    n<<0,-axis(2),axis(1),
       axis(2),0,-axis(0),
       -axis(1),axis(0),0;
    detR=cos(angle)*I+(1-cos(angle))*axis*axis.transpose()+sin(angle)*n;//ʹ���޵����˹��ʽ������ת����

    R=R*detR;//���¾���
    cout<<" Updated Rotation Matrix:"<<endl<<endl;
    cout<<R<<endl;
    cout<<endl;


    Quaterniond detq(1,0.5*w(0),0.5*w(1),0.5*w(2));
    q=q*detq;//������Ԫ��
    cout<<" Updated Quaternion:"<<endl<<endl;
    cout<<q.w()<<" "<<q.x()<<" "<<q.y()<<" "<<q.z()<<endl;
    cout<<endl;

    q.normalized();
    Matrix3d R1=q.toRotationMatrix();
    cout<<" Updated Rotation Matrix from Quaternion:"<<endl<<endl;
    cout<<R1<<endl;
    cout<<endl;

    cout<<"������ת����͸�����Ԫ���õ��Ľ��������ͬ"<<endl;

    return a.exec();
}

