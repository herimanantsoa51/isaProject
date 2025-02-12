
#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H

namespace people
{
    class Infrastructure
    {
    private:
        int nPiece;
    public:
        Infrastructure();
        ~Infrastructure();
        void setNpiece(int newNpiece);
        int getNPiece();
        void displayInfrastructure();
    };
}
#endif