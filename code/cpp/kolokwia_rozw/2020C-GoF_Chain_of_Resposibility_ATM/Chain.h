
//https://www.journaldev.com/1617/chain-of-responsibility-design-pattern-in-java

#include <iostream>
#include <list>

using namespace std;

class IChain {
protected:
    IChain *next_element = nullptr;
public:
    IChain() = default;

    explicit IChain(IChain *next_element_) {
        this->SetNextElement(next_element_);
    }

    void SetNextElement(IChain *next_chain_element) {
        this->next_element = next_chain_element;
    }

    virtual void Process(int amount) = 0;

    virtual ~IChain() { delete next_element; }; // The C++ language guarantees that delete p will do nothing if p is nullptr --> https://isocpp.org/wiki/faq/freestore-mgmt#delete-handles-null
};

class FeeTaker : public IChain {
private:
    const int fee;
public:
    explicit FeeTaker(int _fee_value) : fee(_fee_value) {}

    FeeTaker(int _fee_value, IChain *next_element_) : fee(_fee_value), IChain(next_element_) {}

    void Process(int amount) override {
        cout << "Subtracting fee: " << fee << "$." << endl;
        this->next_element->Process(amount - fee);
    }

    ~FeeTaker() override { cout << "~FeeTaker: " << fee << "$." << endl; }
};

class Dispenser : public IChain {
private:
    const int face_value;
public:
    explicit Dispenser(int _face_value) : face_value(_face_value) {}

    Dispenser(int _face_value, IChain *next_element_) : face_value(_face_value), IChain(next_element_) {}

    void Process(int amount) override {
        if (amount >= face_value) {
            int banknotes = amount / face_value;
            int remainder = amount % face_value;
            cout << "To dispense: " << banknotes << " x " << face_value << "$ banknote." << endl;
            if (remainder != 0) {
                if (this->next_element != nullptr)
                    this->next_element->Process(remainder);
                else
                    cout << "Can't dispense further. Remainder: " << remainder << "$ < banknote face value: " << face_value << "$." << endl;
            }
        } else {
            if (this->next_element != nullptr)
                this->next_element->Process(amount);
            else
                cout << "Can't dispense further... Remainder: " << amount << "$ < banknote face value: " << face_value << "$." << endl;
        }
    }

    ~Dispenser() override { cout << "~Dispenser: " << face_value << "$." << endl; }
};

class ATM {
private:
    IChain *chain_front;
public:
    explicit ATM(IChain *_chain_front) : chain_front(_chain_front) {};

    void WithdrawCash(int amount) { chain_front->Process(amount); }

    ~ATM() { delete chain_front; }
};
