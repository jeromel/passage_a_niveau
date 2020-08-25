#ifndef FEU_H
#define FEU_H

class Feu {
    private:
        int _numeroPin;

    public:
        Feu(int numeroPin) {
            _numeroPin = numeroPin;
        }
        
        void Allumer();

        void Eteindre();
};

#endif
