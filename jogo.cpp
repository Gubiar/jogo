// @author: Gustavo Matos Lázaro
// @RA: 2104512
// @Data: 06 Dez 2020
// @Brief: Jogo de terror hardcore solicitado como avaliacao da P3 da disciplina de POO


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//------------------------------Comodos-----------------------------------------
class AbstrctComodo{
    private:
        string nomeComodo;

        bool temArma = false;
        bool temMunicao = false;
        bool temMonstro = false;

        string nomeArma;
        string tipoMunicao;
        string tipoMonstro;

        int vidaMonstro;

        bool temSoro = false;


    public:
        vector<AbstrctComodo*> *comodosAcessiveis = new vector<AbstrctComodo*>;
        vector<int> caminhos;
        void setNomeComodo(string nomeComodo){
            this->nomeComodo = nomeComodo;
        }

        virtual vector<AbstrctComodo*> setComodos(){};
        virtual vector<int> getComodosAcessiveis(){};
        
        string getComodoNome(){
            return this->nomeComodo;
        }
        void printComodosAcessiveis(){
            cout << "\nComodos Acessiveis:" << endl;
            for (size_t i = 0; i < comodosAcessiveis->size(); i++){
                cout << comodosAcessiveis->at(i)->nomeComodo << " - Opcao:" << i << endl;
            }
        }
        virtual void mover(){};

        void setTemArma(bool temArma){
            this->temArma = temArma;
        }
        void setTemMunicao(bool temMunicao){
            this->temMunicao = temMunicao;
        }
        void setNomeArma(string nomeArma){
            this->nomeArma = nomeArma;
        }
        void setTipoMunicao(string tipoMunicao){
            this->tipoMunicao = tipoMunicao;
        }
        void setTemMonstro(bool temMonstro){
            this->temMonstro = temMonstro;
        }
        void setTipoMonstro(string tipoMonstro){
            this->tipoMonstro = tipoMonstro;
        }
        void setVidaMonstro(int vidaMonstro){
            this->vidaMonstro = vidaMonstro;
        }
        void setTemSoro(bool temSoro){
            this->temSoro = temSoro;
        }

        bool getTemArma(){
            return this->temArma;
        }
        bool getTemMunicao(){
            return this->temMunicao;
        }
        string getNomeArma(){
            return this->nomeArma;
        }
        string getTipoMunicao(){
            return this->tipoMunicao;
        }
        bool getTemMonstro(){
            return this->temMonstro;
        }
        string getTipoMonstro(){
            return this->tipoMonstro;
        }
        int getVidaMonstro(){
            return this->vidaMonstro;
        }
        bool getTemSoro(){
            return this->temSoro;
        }

};

class Sala :public AbstrctComodo{
    public:
        vector<int> getComodosAcessiveis() override{
            cout <<"\nComodos Acessiveis:" << endl;
            cout << "Cozinha - 1" << endl;
            cout <<"Laboratorio - 2" << endl;
            cout << "Corredor - 3" << endl;
            caminhos.push_back(1);
            caminhos.push_back(2);
            caminhos.push_back(3);
            return caminhos;
        }
        Sala(){
            setNomeComodo("Sala");
        }
};

class Laboratorio :public AbstrctComodo{
    public:
        vector<int> getComodosAcessiveis() override{
            cout <<"\nComodos Acessiveis:" << endl;
            cout << "Sala - 0" << endl;
            caminhos.push_back(0);
            return caminhos;
        }
        Laboratorio(){
            setNomeComodo("Laboratorio");   
        }
};

class Cozinha :public AbstrctComodo{
    public:
        vector<int> getComodosAcessiveis() override{
            cout <<"\nComodos Acessiveis:" << endl;
            cout << "Sala - 0" << endl;
            caminhos.push_back(0);
            return caminhos;
        }
        Cozinha(){
            setNomeComodo("Cozinha");
        }
};

class Corredor :public AbstrctComodo{
    public:
        vector<int> getComodosAcessiveis() override{
            cout <<"\nComodos Acessiveis:" << endl;
            cout << "Sala - 0" << endl;
            cout << "BanheiroB1 - 4" << endl;
            cout << "QuartoQ1 - 5" << endl;
            cout << "QuaartoQ2 - 6" << endl;
            cout << "QuartoQ3 - 7" << endl;
            caminhos.push_back(0);
            caminhos.push_back(4);
            caminhos.push_back(5);
            caminhos.push_back(6);
            caminhos.push_back(7);
            return caminhos;
        }
        Corredor(){
            setNomeComodo("Corredor");
        }
};

class BanheiroB1 :public AbstrctComodo{
    public:
        vector<int> getComodosAcessiveis() override{
            cout <<"\nComodos Acessiveis:" << endl;
            cout << "Corredor - 3" << endl;
            caminhos.push_back(3);
            return caminhos;
        }
        BanheiroB1(){
            setNomeComodo("BanheiroB1"); 
        }
};

class QuartoQ1 :public AbstrctComodo{
    public:
        vector<int> getComodosAcessiveis() override{
            cout <<"\nComodos Acessiveis:" << endl;
            cout << "Corredor - 3" << endl;
            caminhos.push_back(3);
            return caminhos;
        }
        QuartoQ1(){
            setNomeComodo("QuartoQ1");
        }
};

class QuartoQ2 :public AbstrctComodo{
    public:
        vector<int> getComodosAcessiveis() override{
            cout <<"\nComodos Acessiveis:" << endl;
            cout << "Corredor - 3" << endl;
            caminhos.push_back(3);
            return caminhos;
        }
        QuartoQ2(){
            setNomeComodo("QuartoQ2");  
        }
};

class QuartoQ3 :public AbstrctComodo{
    public:
        vector<int> getComodosAcessiveis() override{
            cout <<"\nComodos Acessiveis:" << endl;
            cout << "Corredor - 3" << endl;
            cout << "BanheiroB2 - 8" << endl;
            caminhos.push_back(3);
            caminhos.push_back(8);
            return caminhos;
        }
        QuartoQ3(){
            setNomeComodo("QuartoQ3");
        }
};

class BanheiroB2 :public AbstrctComodo{
    public:
        vector<int> getComodosAcessiveis() override{
            cout <<"\nComodos Acessiveis:" << endl;
            cout << "QuartoQ3 - 7" << endl;
            caminhos.push_back(7);
            return caminhos;
        }
        BanheiroB2(){
            setNomeComodo("BanheiroB2");
        }
};

//------------------------------Armamento-----------------------------------------

class AbstractArma{
    public:
        virtual void gerarArma(AbstrctComodo* Comodo){}
};

class ArmaBereta: public AbstractArma{
    public:
        void gerarArma(AbstrctComodo* Comodo) override{
                int aleatorio = rand()%(8-0+1) + 0;
                if(Comodo->comodosAcessiveis->at(aleatorio)->getTemArma() == false){
                    Comodo->comodosAcessiveis->at(aleatorio)->setTemArma(true);
                    Comodo->comodosAcessiveis->at(aleatorio)->setNomeArma("Bereta");
                }
                else{
                    gerarArma(Comodo);
                }
            }
            ArmaBereta(AbstrctComodo* Comodo){
                gerarArma(Comodo);
            }
};

class ArmaEspingarda: public AbstractArma{
    public:
        void gerarArma(AbstrctComodo* Comodo) override{
                int aleatorio = rand()%(8-0+1) + 0;
                if(Comodo->comodosAcessiveis->at(aleatorio)->getTemArma() == false){
                    Comodo->comodosAcessiveis->at(aleatorio)->setTemArma(true);
                    Comodo->comodosAcessiveis->at(aleatorio)->setNomeArma("Espingarda");
                }
                else{
                    gerarArma(Comodo);
                }
            }
            ArmaEspingarda(AbstrctComodo* Comodo){
                gerarArma(Comodo);
            }
};

class AbstractFactoryArma{
    public:
        virtual AbstractArma * CreateArma(AbstrctComodo* Comodo) const = 0;
};

class ConcretFactoryBereta :public AbstractFactoryArma{
    public:
        AbstractArma * CreateArma(AbstrctComodo* Comodo) const override{
            return new ArmaBereta(Comodo);
        }
        ConcretFactoryBereta(AbstrctComodo* Comodo){
            CreateArma(Comodo);
        }
};

class ConcretFactoryEspingarda :public AbstractFactoryArma{
    public:
        AbstractArma * CreateArma(AbstrctComodo* Comodo) const override{
            return new ArmaEspingarda(Comodo);
        }
        ConcretFactoryEspingarda(AbstrctComodo* Comodo){
            CreateArma(Comodo);
        }
};

//------------------------------Municao--------------------------------

class AbstractMunicao{
    public:
        virtual void gerarMunicao(AbstrctComodo* Comodo){}
};

class MunicaoBereta: public AbstractMunicao{
    public:
        void gerarMunicao(AbstrctComodo* Comodo) override{
            int aleatorio = rand()%(8-0+1) + 0;
            if(Comodo->comodosAcessiveis->at(aleatorio)->getTemMunicao() == false){
                Comodo->comodosAcessiveis->at(aleatorio)->setTemMunicao(true);
                Comodo->comodosAcessiveis->at(aleatorio)->setTipoMunicao("Bereta");
            }else{
                gerarMunicao(Comodo);
            }
        }
        MunicaoBereta(AbstrctComodo* Comodo){
            gerarMunicao(Comodo);
        }
};

class MunicaoEspingarda: public AbstractMunicao{
    public:
        void gerarMunicao(AbstrctComodo* Comodo) override{
            int aleatorio = rand()%(8-0+1) + 0;
            if(Comodo->comodosAcessiveis->at(aleatorio)->getTemMunicao() == false){
                Comodo->comodosAcessiveis->at(aleatorio)->setTemMunicao(true);
                Comodo->comodosAcessiveis->at(aleatorio)->setTipoMunicao("Espingarda");
            }else{
                gerarMunicao(Comodo);
            }
        }
        MunicaoEspingarda(AbstrctComodo* Comodo){
            gerarMunicao(Comodo);
        }
};

class AbstractFactoryMunicao{
    public:
        virtual AbstractMunicao * CreateMunicao(AbstrctComodo* Comodo) const = 0;
};

class ConcretFactoryMunicaoBereta :public AbstractFactoryMunicao{
    public:
        AbstractMunicao * CreateMunicao(AbstrctComodo* Comodo) const override{
            return new MunicaoBereta(Comodo);
        }
        ConcretFactoryMunicaoBereta(AbstrctComodo* Comodo){
            CreateMunicao(Comodo);
        }
};

class ConcretFactoryMunicaoEspingarda :public AbstractFactoryMunicao{
    public:
        AbstractMunicao * CreateMunicao(AbstrctComodo* Comodo) const override{
            return new MunicaoEspingarda(Comodo);
        }
        ConcretFactoryMunicaoEspingarda(AbstrctComodo* Comodo){
            CreateMunicao(Comodo);
        }
};

//------------------------------Monstros-----------------------------------------
class AbstractMonstro{
    public:
        virtual void gerarMonstro(AbstrctComodo* Comodo){}
};

class MonstroFraco: public AbstractMonstro{
    public:
        void gerarMonstro(AbstrctComodo* Comodo) override{
            int aleatorio = rand()%(8-1+1) + 1;
            if(Comodo->comodosAcessiveis->at(aleatorio)->getTemMonstro() == false){
                Comodo->comodosAcessiveis->at(aleatorio)->setTemMonstro(true);
                Comodo->comodosAcessiveis->at(aleatorio)->setTipoMonstro("BlackPhantom");
                Comodo->comodosAcessiveis->at(aleatorio)->setVidaMonstro(1);
            }
            else{
                gerarMonstro(Comodo);
            }
        }
        MonstroFraco(AbstrctComodo* Comodo){
            gerarMonstro(Comodo);
        }
};

class MonstroForte : public AbstractMonstro{
    public:
        void gerarMonstro(AbstrctComodo* Comodo) override{
            int aleatorio = rand()%(8-1+1) + 1;
            if(Comodo->comodosAcessiveis->at(aleatorio)->getTemMonstro() == false){
                Comodo->comodosAcessiveis->at(aleatorio)->setTemMonstro(true);
                Comodo->comodosAcessiveis->at(aleatorio)->setTipoMonstro("DarkPhantom");
                Comodo->comodosAcessiveis->at(aleatorio)->setVidaMonstro(2);
            }
            else{
                gerarMonstro(Comodo);
            }
        }
        MonstroForte(AbstrctComodo* Comodo){
            gerarMonstro(Comodo);
        }
};

class AbstractFactoryMonstro{
    public:
        virtual AbstractMonstro * CreatMonstro(AbstrctComodo* Comodo) const = 0;
};

class ConcretFactoryMonstroFraco: public AbstractFactoryMonstro{
    public:
        AbstractMonstro * CreatMonstro(AbstrctComodo* Comodo) const override{
            return new MonstroFraco(Comodo);
        }
        ConcretFactoryMonstroFraco(AbstrctComodo* Comodo){
            CreatMonstro(Comodo);
        }

};

class ConcretFactoryMonstroForte: public AbstractFactoryMonstro{
    public:
        AbstractMonstro * CreatMonstro(AbstrctComodo* Comodo) const override{
            return new MonstroForte(Comodo);
        }
        ConcretFactoryMonstroForte(AbstrctComodo* Comodo){
            CreatMonstro(Comodo);
        }
};

//------------------------------Personagem-----------------------------------------

class Personagem{
    private:
        static Personagem* instance;
        int vida = 2;
        bool temBereta;
        int municaoBereta;
        int municaoBeretaEncontrada;
        bool temEspingarda;
        int municaoEspingarda;
        int municaoEspingardaEncontrada;
        bool temSoro = false;
        Personagem(){}
    public:
        static Personagem* getIntance();

        void setVida(int vida){
            this->vida = vida;
        }
        void setTemBereta(bool bereta){
            this->temBereta = bereta;
        }
        void setTemEspingarda(bool espingarda){
            this->temEspingarda = espingarda;
        }
        void setMunicaoBereta(int municaoBereta){
            this->municaoBereta += municaoBereta;
        }
        void setMunicaoEspingarda(int municaoEspingarda){
            this->municaoEspingarda += municaoEspingarda;
        }
        void setMunicaoBeretaEncontrada(int municaoBeretaEncontrada){
            this->municaoBeretaEncontrada += municaoBeretaEncontrada;
        }
        void setMunicaoEspingardaEncontrada(int municaoEspingardaEncontrada){
            this->municaoEspingardaEncontrada += municaoEspingardaEncontrada;
        }
        void setTemSoro(bool soro){
            this->temSoro = soro;
        }
        int getVida(){
            return this->vida;
        }
        bool getTemBereta(){
            return this->temBereta;
        }
        bool getTemEspingarda(){
            return this->temEspingarda;
        }
        int getMunicaoBereta(){
            return this->municaoBereta;
        }
        int getMunicaoEspingarda(){
            return this->municaoEspingarda;
        }
        int getMunicaoBeretaEncontrada(){
            return this->municaoBeretaEncontrada;
        }
        int getMunicaoEspingardaEncontrada(){
            return this->municaoEspingardaEncontrada;
        }
        bool getTemSoro(){
            return this->temSoro;
        }
};

Personagem* Personagem::instance = 0;
Personagem* Personagem::getIntance(){
    if (instance == 0){
        instance = new Personagem();
    }
    return instance;
}

//------------------------------Cliente-----------------------------------------

class Cliente :public AbstrctComodo{
    public:
        int valor = 0;

        vector<AbstrctComodo*> setComodos(){
            if (comodosAcessiveis->empty()){
                AbstrctComodo* var;
                var = new Sala(); //0
                comodosAcessiveis->push_back(var);
                var = new Cozinha(); //1
                comodosAcessiveis->push_back(var);
                var= new Laboratorio(); //2
                comodosAcessiveis->push_back(var);
                var = new Corredor(); //3
                comodosAcessiveis->push_back(var);
                var = new BanheiroB1(); //4
                comodosAcessiveis->push_back(var);
                var = new QuartoQ1(); //5
                comodosAcessiveis->push_back(var);
                var = new QuartoQ2(); //6
                comodosAcessiveis->push_back(var);
                var = new QuartoQ3(); //7
                comodosAcessiveis->push_back(var);
                var = new BanheiroB2(); //8
                comodosAcessiveis->push_back(var);
            }
        return *comodosAcessiveis;
}

        void creatItens(AbstrctComodo* Comodo){
            AbstractFactoryArma* quadrada;
            quadrada = new ConcretFactoryBereta(Comodo);
            quadrada = new ConcretFactoryEspingarda(Comodo);

            AbstractFactoryMunicao* bala;
            bala = new ConcretFactoryMunicaoBereta(Comodo);
            bala = new ConcretFactoryMunicaoBereta(Comodo);
            bala = new ConcretFactoryMunicaoEspingarda(Comodo);
            bala = new ConcretFactoryMunicaoEspingarda(Comodo);
        }

        void creatMonstros(AbstrctComodo* Comodo){
            AbstractFactoryMonstro* setePele;
            setePele = new ConcretFactoryMonstroForte(Comodo);
            setePele = new ConcretFactoryMonstroForte(Comodo);
            setePele = new ConcretFactoryMonstroFraco(Comodo);
            setePele = new ConcretFactoryMonstroFraco(Comodo);
            setePele = new ConcretFactoryMonstroFraco(Comodo);
        }

        void gerarSoro(AbstrctComodo* Comodo){
            int aleatorio = rand()%(8-1+1) + 1;
            Comodo->comodosAcessiveis->at(aleatorio)->setTemSoro(true);
        }

        void movendo(AbstrctComodo* Comodo, int valor, Personagem* Personagem){ //Inicio funcao movendo
                    cout << "Movendo para: " << Comodo->comodosAcessiveis->at(valor)->getComodoNome() << endl;
                    AbstrctComodo* proxComodo = new AbstrctComodo();
                    proxComodo = Comodo->comodosAcessiveis->at(valor);
                    Cliente* Cliente2;
                    Cliente2 = new Cliente(proxComodo, Personagem);
        } 
        
        void mover(AbstrctComodo* Comodo, Personagem* Personagem){ //Inicio da funcao mover
            Comodo->caminhos =  Comodo->getComodosAcessiveis();
            cout << "\nQual posicao voce deseja ir? " <<endl;
            int valor =0;
            cin >> valor;

            if(Comodo->getComodoNome() == "Sala"){
                ganhou(Personagem);
                try{
                    
                    if(valor == 1){ //Cozinha
                        movendo(Comodo, valor, Personagem);
                    }
                    if(valor == 2){ //Laboratorio
                        movendo(Comodo, valor, Personagem);
                    }
                    if(valor == 3){ //Corredor
                        movendo(Comodo, valor, Personagem);                    
                    }

                    throw(runtime_error("Opcao invalida"));
                }
                catch(const exception& e)
                {
                    cout << "Opcao invalida" << '\n';
                    mover(Comodo, Personagem);
                }
            }

            if(Comodo->getComodoNome() == "Cozinha"){
                try{

                    if(valor == 0){ //Sala
                        movendo(Comodo, valor, Personagem);
                    } 

                    throw(runtime_error("Opcao invalida"));
                }
                catch(const exception& e)
                {
                    cout << "Opcao invalida" << '\n';
                    mover(Comodo, Personagem);
                }
            }

            if(Comodo->getComodoNome() == "Laboratorio"){
                try{

                    if(valor == 0){ //Sala
                        movendo(Comodo, valor, Personagem);
                    }
                    
                    throw(runtime_error("Opcao invalida"));
                }
                catch(const exception& e)
                {
                    cout << "Opcao invalida" << '\n';
                    mover(Comodo, Personagem);
                }
            }

            if(Comodo->getComodoNome() == "Corredor"){
                try{

                    if(valor == 0){ //Sala
                        movendo(Comodo, valor, Personagem);
                    } 
                    if(valor == 4){ //BanheiroB1
                        movendo(Comodo, valor, Personagem);
                    } 
                    if(valor == 5){ //QuartoQ1
                        movendo(Comodo, valor, Personagem);
                    } 
                    if(valor == 6){ //QuartoQ2
                        movendo(Comodo, valor, Personagem);
                    } 
                    if(valor == 7){ //QuartoQ3
                        movendo(Comodo, valor, Personagem);
                    }
                    
                    throw(runtime_error("Opcao invalida"));
                }
                catch(const exception& e)
                {
                    cout << "Opcao invalida" << '\n';
                    mover(Comodo, Personagem);
                }
            }

            if(Comodo->getComodoNome() == "BanheiroB1"){
                try{

                    if(valor == 4){ //Corredor
                        movendo(Comodo, valor, Personagem);
                    }
                    
                    throw(runtime_error("Opcao invalida"));
                }
                catch(const exception& e)
                {
                    cout << "Opcao invalida" << '\n';
                    mover(Comodo, Personagem);
                }
            }

            if(Comodo->getComodoNome() == "QuartoQ1"){
                try{

                    if(valor == 4){ //Corredor
                    movendo(Comodo, valor, Personagem);
                } 
                    
                    throw(runtime_error("Opcao invalida"));
                }
                catch(const exception& e)
                {
                    cout << "Opcao invalida" << '\n';
                    mover(Comodo, Personagem);
                }
            }

            if(Comodo->getComodoNome() == "QuartoQ2"){
                try{

                    if(valor == 4){ //Corredor
                        movendo(Comodo, valor, Personagem);
                    }
                    
                    throw(runtime_error("Opcao invalida"));
                }
                catch(const exception& e)
                {
                    cout << "Opcao invalida" << '\n';
                    mover(Comodo, Personagem);
                }
            }

            if(Comodo->getComodoNome() == "QuartoQ3"){
                try{

                    if(valor == 4){ //Corredor
                        movendo(Comodo, valor, Personagem);
                    }
                    if(valor == 8){ //BanheiroB2
                        movendo(Comodo, valor, Personagem);
                    }
                    
                    throw(runtime_error("Opcao invalida"));
                }
                catch(const exception& e)
                {
                    cout << "Opcao invalida" << '\n';
                    mover(Comodo, Personagem);
                }
            }

            if(Comodo->getComodoNome() == "BanheiroB2"){   
                try{
                    if(valor == 7){ //QuartoQ3
                        movendo(Comodo, valor, Personagem);
                    }
                    
                    throw(runtime_error("Opcao invalida"));
                }
                catch(const exception& e)
                {
                    cout << "Opcao invalida" << '\n';
                    mover(Comodo, Personagem);
                } 
            }

        } //Fim da Funcao Mover

        void temMonstro(AbstrctComodo* Comodo){
            if (Comodo->getTemMonstro()){
                if (Comodo->getTipoMonstro() == "BlackPhantom"){
                    cout << "\nTem um BlackPhantom no comodo!" << endl;
                    cout <<"Se voce procurar ou mover, ira tomar 1 hit do monstro!" << endl;
                }
                if (Comodo->getTipoMonstro() == "DarkPhantom"){
                    cout << "\nTem um DarkPhantom no comodo!" << endl;
                    cout <<"Se voce procurar ou mover, ira tomar 1 hit do monstro!" << endl;
                }
            }
        }

        void seMorreu(Personagem* Personagem){
            if(Personagem->getVida() <= 0){
                cout << "\nVoce morreu. Game over" << endl;
                abort();
            }
        }

        void ganhou(Personagem* Personagem){
            if (Personagem->getTemSoro()){
                cout << "GG, voce ganhou!" << endl;
                abort();
            }
            
        }

        void atacado(Personagem* Personagem){
            cout << "Voce foi atacado" << endl;
            Personagem->setVida(Personagem->getVida()-1);
            seMorreu(Personagem);
        }

        void atirouMonstro(AbstrctComodo* Comodo){
            cout << "PAHHHH! Voce atirou no monstro!" << endl;
            Comodo->setVidaMonstro(Comodo->getVidaMonstro()-1);
        }

        void tiroBereta(AbstrctComodo* Comodo, Personagem* Personagem){
            if(Personagem->getMunicaoBereta() > 0){
                atirouMonstro(Comodo);
                matouMonstro(Comodo);
                Personagem->setMunicaoBereta(Personagem->getMunicaoBereta()-1);
                
            }else{
                cout << "Voce nao tem municao na arma" << endl;
                if (Personagem->getMunicaoBeretaEncontrada() > 0){
                    cout << "Recarregando" << endl;
                    Personagem->setMunicaoBereta(Personagem->getMunicaoBeretaEncontrada());
                    Personagem->setMunicaoBeretaEncontrada(0);
                    atirouMonstro(Comodo);
                    Personagem->setMunicaoBereta(Personagem->getMunicaoBereta()-1);
                    matouMonstro(Comodo);
                }else{
                    atacado(Personagem);
                    seMorreu(Personagem);
                }
                
            }
        }

        void tiroEspingarda(AbstrctComodo* Comodo, Personagem* Personagem){
            if(Personagem->getMunicaoEspingarda() > 0){
                atirouMonstro(Comodo);
                matouMonstro(Comodo);
                Personagem->setMunicaoEspingarda(Personagem->getMunicaoEspingarda()-1);
                                    
            }else{
                cout << "Voce nao tem municao na arma" << endl;
                if (Personagem->getMunicaoEspingardaEncontrada() > 0){
                    cout << "Recarregando" << endl;
                    Personagem->setMunicaoEspingarda(Personagem->getMunicaoEspingardaEncontrada());
                    Personagem->setMunicaoEspingardaEncontrada(0);
                    atirouMonstro(Comodo);
                    Personagem->setMunicaoEspingarda(Personagem->getMunicaoEspingarda()-1);
                    matouMonstro(Comodo);
                }else{
                    atacado(Personagem);
                    seMorreu(Personagem);
                }
            }
        }

        void matouMonstro(AbstrctComodo* Comodo){
            if (Comodo->getVidaMonstro() == 0){
                cout << "Voce matou o " << Comodo->getTipoMonstro() << endl;
                Comodo->setTemMonstro(false);
            }
        }

        void procuraraItens(AbstrctComodo* Comodo, Personagem* Personagem){
            if(Comodo->getTemArma()){
                if(Comodo->getNomeArma() == "Bereta"){
                    cout << "Voce achou uma Bereta" << endl;
                    Personagem->setTemBereta(true);
                    Comodo->setTemArma(false);
                }
                if(Comodo->getNomeArma() == "Espingarda"){
                    cout << "Voce achou uma Espingarda" << endl;
                    Personagem->setTemEspingarda(true);
                    Comodo->setTemArma(false);
                }
            }
            if(Comodo->getTemMunicao()){
                if(Comodo->getTipoMunicao() == "Bereta"){
                    cout << "Voce achou municao de Bereta" << endl;
                    Personagem->setMunicaoBeretaEncontrada(1);
                    Comodo->setTemMunicao(false);
                }
                if(Comodo->getTipoMunicao() == "Espingarda"){
                    cout << "Voce achou municao de Espingarda" << endl;
                    Personagem->setMunicaoEspingardaEncontrada(1);
                    Comodo->setTemMunicao(false);
                }
            }
            if(Comodo->getTemSoro()){
                cout << "Voce achou o soro, leve-o para  sala e conclua teu objetivo!" << endl;
                Personagem->setTemSoro(true);
                Comodo->setTemSoro(false);
            }
            else{
                cout << "Voce nao achou nada" << endl;
            }
        }

        void escolha(AbstrctComodo* Comodo, Personagem* Personagem){
            cout << "-------------------------------------" << endl;
            cout << "Voce esta no comodo: " << Comodo->getComodoNome() << endl;
            temMonstro(Comodo);

            cout << "Atacar - 1\tProcurar - 2\tMover - 3" << endl;
            int opcao;
            cin >> opcao;

            try{

                if (opcao == 1){ //Atacar
    
                    if(Comodo->getTemMonstro()){
                        if(Personagem->getTemBereta() || Personagem->getTemEspingarda()){
                            if(Personagem->getTemBereta() && !Personagem->getTemEspingarda()){
                                tiroBereta(Comodo, Personagem);
                            }
                            if(!Personagem->getTemBereta() && Personagem->getTemEspingarda()){
                                tiroEspingarda(Comodo, Personagem);
                            }
                            if(Personagem->getTemBereta() && Personagem->getTemEspingarda()){
                                cout << "Escolha com qual arma deseja atirar:\n1 - Bereta\n2 - Espingarda" <<endl;
                                int val;
                                cin>> val;
                                if(val == 1){
                                    tiroBereta(Comodo, Personagem);
                                }
                                if(val == 2){
                                    tiroEspingarda(Comodo, Personagem);
                                }
                                if(val != 1 && val != 2){
                                    cout << "Opcao Invalida. Tomou um hit do monstro pra ficar esperto" << endl;
                                    atacado(Personagem);
                                    seMorreu(Personagem);
                                }
                            }
                        }else{
                            cout << "Voce nao tem armas para atacar" <<endl;
                            atacado(Personagem);
                            seMorreu(Personagem);
                        }
                    }else{
                        if(Personagem->getTemBereta() || Personagem->getTemEspingarda()){

                            if(Personagem->getTemBereta() && !Personagem->getTemEspingarda()){
                                if (Personagem->getMunicaoBereta() > 0){
                                    Personagem->setMunicaoBereta(Personagem->getMunicaoBereta()-1);
                                }else{
                                    cout << "Voce nao tem municao" << endl;
                                }
                            }

                            if(!Personagem->getTemBereta() && Personagem->getTemEspingarda()){
                                if (Personagem->getMunicaoEspingarda() > 0){
                                    Personagem->setMunicaoEspingarda(Personagem->getMunicaoEspingarda()-1);
                                }else{
                                    cout << "Voce nao tem municao" << endl;
                                }
                            }

                            if(Personagem->getTemBereta() && Personagem->getTemEspingarda()){
                                cout << "Escolha com qual arma deseja atirar:\n1 - Bereta\n2 - Espingarda" <<endl;
                                int val;
                                cin>> val;
                                if(val == 1){
                                    if (Personagem->getMunicaoBereta() > 0){
                                        Personagem->setMunicaoBereta(Personagem->getMunicaoBereta()-1);
                                    }else{
                                        cout << "Voce nao tem municao" << endl;
                                    }
                                }
                                if(val == 2){
                                    if (Personagem->getMunicaoEspingarda() > 0){
                                        Personagem->setMunicaoEspingarda(Personagem->getMunicaoEspingarda()-1);
                                    }else{
                                        cout << "Voce nao tem municao" << endl;
                                    }
                                }
                                if(val != 1 && val != 2){
                                    cout <<"Opcao invalida, sorte sua que nao tem monstro no ambiente!!" <<endl;
                                }
                            }
                        }
                    }
                    escolha(Comodo, Personagem);
                }

                if (opcao == 2){ //Procurar
                    
                    if(Comodo->getTemMonstro()){
                        atacado(Personagem);
                        seMorreu(Personagem);
                        cout << Personagem->getVida() << endl;
                    }
                    procuraraItens(Comodo, Personagem);
                    escolha(Comodo, Personagem);
                }

                if (opcao == 3){ //Movimentar

                    if(Comodo->getTemMonstro()){
                        atacado(Personagem);
                        seMorreu(Personagem);
                    }
                    mover(Comodo, Personagem);
                }
                throw(runtime_error("Opcao invalida"));
            }
            catch(const exception& e){
                cout << "Opcao invalida" << endl;
                escolha(Comodo, Personagem);
            }
        }

        Cliente(){}
        Cliente(AbstrctComodo* Comodo, Personagem* Personagem){

            *Comodo->comodosAcessiveis = setComodos();
            creatItens(Comodo);
            creatMonstros(Comodo);
            gerarSoro(Comodo);
            escolha(Comodo, Personagem);
            
        }
};

int main(){
    srand((unsigned)time(0));
    cout << "\nBem vindo ao Resident Evil 19" << endl;
    cout << "Seu objetivo e achar um soro sagrado e voltar para a sala" << endl;
    cout << "Tem monstros espalhados pela casa, cuidado!" << endl;
    cout <<"Voce pode procurar itens nos comodos para te ajudar nessa jornada" << endl;
    cout <<"Boa sorte, voce vai precisar..." << endl;
    AbstrctComodo* lugar = new Sala();
    Personagem* personagem = Personagem::getIntance();
    Cliente* teste = new Cliente(lugar, personagem);

    return 0;
}