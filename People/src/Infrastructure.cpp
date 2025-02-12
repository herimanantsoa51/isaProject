#include "../header/Infrastructure.h"
#include <iostream>
using namespace std;
using namespace people;
Infrastructure::Infrastructure()
{
    cout<<"un infrastructure a ete cree"<<endl;
    nPiece=0;
}
Infrastructure::~Infrastructure()
{
    cout<<"un infrastructure a ete cree"<<endl;
}
void Infrastructure::setNpiece(int newNpiece)
{
    nPiece=newNpiece;
}
int Infrastructure::getNPiece()
{
    return(nPiece);
}
void Infrastructure::displayInfrastructure()
{
    cout<<"Info Infrastructure:\nNombre de Piece:"<<nPiece<<endl;
}
