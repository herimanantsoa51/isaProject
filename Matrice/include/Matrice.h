
#include <vector>

using namespace std;
namespace isa
{   

 
    class Matrice
    {   

         
    private: 
        vector<vector<float>> components;
        int nLine;
        int nCol;
    public:
        Matrice();
        ~Matrice();
        Matrice(int nLine,int nCol);
        void setComponents(vector<vector<float>> newComponents);
        void setComponent(int i,int j,float newComponent);
        float getComponent(int i,int j);
        vector<vector<float>> getComponents();
        int  getNline();
        int getNCol();
        void display();
        friend Matrice operator+(Matrice M1,Matrice M2); 
        friend Matrice operator-(Matrice M1,Matrice M2);
        friend Matrice operator*(Matrice M1,Matrice M2);
        friend Matrice operator^(Matrice M,int n);
        friend void operator*=(Matrice& M1,Matrice M2);
        friend void operator -=(Matrice& M1,Matrice M2);
    };
    Matrice operator+(Matrice M1,Matrice M2);
    Matrice operator-(Matrice M1,Matrice M2);
    Matrice operator*(Matrice M1,Matrice M2);
    Matrice operator^(Matrice M,int n);
    void operator*=(Matrice& M1,Matrice M2);
    void operator +=(Matrice& M1,Matrice M2);
    void operator -=(Matrice& M1,Matrice M2);

    
   
    
}
 
