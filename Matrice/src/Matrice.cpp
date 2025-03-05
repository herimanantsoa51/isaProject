#include "../include/Matrice.h"
#include <iostream>
#include <iomanip>
using namespace std;
using namespace isa;
Matrice::Matrice()
{
    cout << "Une Matrice a ete cree" <<endl;
    nCol=0;
    nLine=0;
}

Matrice::~Matrice()
{
    cout << "Une Matrice a ete supprimee" <<endl;
}
Matrice::Matrice(int nLine,int nCol)
{
    this->nLine=nLine;
    this->nCol=nCol;
    components.resize(nLine);
    for(int i=0;i<nLine;i++)
    {
        components[i].resize(nCol);
    }
}
void Matrice::setComponents(vector<vector<float>> newComponents)
{
    components=newComponents;
    nLine=components.size();
    nCol=components[0].size();
}
void Matrice::setComponent(int i,int j,float newComponent)
{
    components[i][j]=newComponent;
}
float Matrice::getComponent(int i,int j)
{
    return(components[i][j]);
}
vector<vector<float>> Matrice::getComponents()
{
    return(components);
}
int Matrice::getNline()
{
    return(nLine);
}
int Matrice::getNCol()
{
    return(nCol);
}
void Matrice::display()
{
    for(int i=0;i<nLine;i++)
    {   
        cout << "[ ";
        for(int j=0;j<nCol;j++)
        {
            cout << setprecision(2) << setw(5) << components[i][j];
        }
        cout << " ]";
        cout <<endl;
    }
    cout <<endl;
}

Matrice isa::operator+(Matrice M1, Matrice M2)
{
    if (M1.nLine != M2.nLine || M1.nCol != M2.nCol)
    {
        cout << "Les deux matrices ne sont pas de meme taille" << endl;
        return Matrice();
    }

    Matrice result(M1.nLine, M1.nCol);
    for (int i = 0; i < M1.nLine; ++i)
    {
        for (int j = 0; j < M1.nCol; ++j)
        {
            result.components[i][j] = M1.components[i][j] + M2.components[i][j];
        }
    }
    return result;
}
Matrice isa::operator-(Matrice M1, Matrice M2)
{
    if (M1.nLine != M2.nLine || M1.nCol != M2.nCol)
    {
        cout << "Les deux matrices ne sont pas de meme taille" << endl;
        return Matrice();
    }

    Matrice result(M1.nLine, M1.nCol);
    for (int i = 0; i < M1.nLine; ++i)
    {
        for (int j = 0; j < M1.nCol; ++j)
        {
            result.components[i][j] = M1.components[i][j] - M2.components[i][j];
        }
    }
    return (result);
}   
Matrice isa::operator*(Matrice M1,Matrice M2)
{
    if (M1.nLine != M2.nCol )
    {
        cout << "Erreur de  multiplication de Matrice M1.nline="<< M1.nLine <<" M2.ncol=" << M2.nCol  << endl;
        return Matrice();
    }
    Matrice result(M1.nLine,M2.nCol);
    for (int i = 0 ; i < result.nLine; i++)
    {
        for(int j=0 ; j< result.nCol;j++)
        {   
            result.components[i][j] = 0;

            for (int k = 0; k < M1.nCol; k++)
            {
                result.components[i][j] += M1.components[i][k] * M2.components[k][j];
            }  
        }
    }
    return(result);    
}
Matrice isa::operator^(Matrice M,int n)
{
    if (M.nCol<=0 || M.nLine <= 0 || n<=0)
    {
        cout << "Erreur de calcul de puissance" << endl;
        return M;
    }
    Matrice result(M.nLine,M.nCol);
    int i,j;
    for ( i = 0; i < result.nLine; i++)
    {
        for ( j = 0; j < result.nCol; j++)
        {
            result.components[i][j]=1;
        } 
    }
    for ( i = 0; i < n; i++)
    {
        result *= M;
    }
    return(result);    
}
void isa::operator*=(Matrice& M1,Matrice M2)
{   
    M1 = M1*M2;
}
void isa::operator+=(Matrice& M1,Matrice M2)
{
    M1 = M1+M2;
}
void isa::operator-=(Matrice& M1,Matrice M2)
{
    M1 = M1-M2;
}