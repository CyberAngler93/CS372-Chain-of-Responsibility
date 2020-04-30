#include "help.hpp"
#include <iostream>
#include <vector>


void clientRequests(std::shared_ptr<HelpDesk> helper){
    std::vector<std::string> commands = {"Accounting", "Payments", "Repairs", "Payments", "Repairs", "Accounting"};
    for(const std::string & c : commands) {
        std::cout << "HelpDesk request to: " << c << "!\n";
        const std::string result = helper->Help(c); 
        if (!result.empty()){
            std::cout << " " << result;
        }
        else{
            std::cout << "Not Availble to Process \n";
        }
    }
}

int main(){
    auto accounting = std::make_shared<AccountsHelper>();
    auto billing = std::make_shared<PaymentsHelper>();
    auto repairs = std::make_shared<RepairHelper>();
    accounting->setNext(billing)->setNext(repairs);
    std::cout << accounting->Help("Billing") << "\n";
    std::cout << "Chain of command: Acccounting > Payments > Repairs \n\n";
    clientRequests(accounting);

    std::cout << "\n Chain starting at Payments > Repairs \n\n";
    clientRequests(billing);
    return 0;
}

