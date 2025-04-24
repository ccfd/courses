// https://www.baeldung.com/java-state-design-pattern
#include <iostream>

using namespace std;

class IState {
public:
    virtual IState *GetNextState() = 0;
    virtual string GetStatus() = 0;
    virtual ~IState() = default;
};

class Peasant {
private:
    IState *state = nullptr;
public:
    Peasant() = default;

    void NextState() {
        IState *new_state = state->GetNextState();
        delete state;
        state = new_state;
    }

    void SetState(IState *new_state) {
        delete state;
        state = new_state;
    }

    void PrintState() {
        cout << state->GetStatus() << endl;
    }

    ~Peasant(){
        delete state;
    }
};

//////////////////////////////////////////////////////////////////////////
// States - declarations
//////////////////////////////////////////////////////////////////////////

class GoWork : public IState {
public:
    IState *GetNextState() override;
    string GetStatus() override {return "Going to work...";} ;
//    ~GoWork()override {cout<<"~GoWork"<<endl;}
};

class Harvest : public IState {
public:
    IState *GetNextState() override;
    string GetStatus() override { return "Harvesting..."; };
//    ~HarvestState()override {cout<<"~GoWork"<<endl;}
};

class ReturnHome : public IState {
public:
    IState *GetNextState() override;
    string GetStatus() override  { return "Walking back home..."; };
//    ~ReturnHome()override {cout<<"~GoWork"<<endl;}
};

//////////////////////////////////////////////////////////////////////////
// Implementations
//////////////////////////////////////////////////////////////////////////

IState *GoWork::GetNextState() {
    return new Harvest();
}

IState *Harvest::GetNextState() {
    return new ReturnHome();
}

IState *ReturnHome::GetNextState() {
    return new GoWork();
}

int main(int argc, char *argv[]) {
    Peasant *pPeasant = new Peasant();
    pPeasant->SetState(new GoWork());
    pPeasant->PrintState();

    for (int i = 0; i < 10; ++i)
    {
        pPeasant->NextState();
        pPeasant->PrintState();
    }

    delete pPeasant;
    return EXIT_SUCCESS;
};

// Output:

// Going to work...
// Harvesting...
// Walking back home...
// Going to work...
// Harvesting...
// Walking back home...
// Going to work...
// Harvesting...
// Walking back home...
// Going to work...
// Harvesting...