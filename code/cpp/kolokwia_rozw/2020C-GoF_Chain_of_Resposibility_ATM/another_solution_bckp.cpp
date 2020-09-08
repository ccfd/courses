//
// Created by grzegorz on 07.09.2020.
//

//    ATM_v2 atm_v2;
//    atm_v2.AddNewElementToChain(new FeeTaker(20));  // order of chain elements matters
//    atm_v2.AddNewElementToChain(new Dispenser(100));
//    atm_v2.AddNewElementToChain(new Dispenser(50));
//    atm_v2.AddNewElementToChain(new Dispenser(20));
//    atm_v2.AddNewElementToChain(new Dispenser(10));
//    // process the requests
//    cout << "---------------" << endl;
//    atm_v2.WithdrawCash(610);
//    cout << "---------------" << endl;
//    atm_v2.WithdrawCash(50);
//    cout << "---------------" << endl;
//    atm_v2.WithdrawCash(123);
//    cout << "---------------" << endl;


// THIS IS NOT RELEVANT
//class ATM_v2 {
//private:
//    list<IChain*> chain;
//public:
//    ATM_v2() = default;
//
//    void AddNewElementToChain(IChain *chain_element) {
//        IChain *back = chain.back();
//        chain.emplace_back(chain_element);
//        if (back != nullptr) {
//            back->SetNextElement(chain_element);
//        }
//    }
//
//    void WithdrawCash(int amount) {
//        chain.front()->Process(amount);
//    }
//
//    ~ATM_v2() { delete chain.front(); } //for (auto &c : chain) {delete c;}
//};
