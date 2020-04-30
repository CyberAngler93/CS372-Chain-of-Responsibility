#include "helper.hpp"
#include <iostream>
#include <vector>


void clientRequests(HelpDesk & helper){
    std::vector<std::string> commands = {"Accounting", "Payments", "Repairs"};
    for(const std::string & c : commands) {
        std::cout << "HelpDesk request to: " << c << "!\n";
        const std::string result = helper.Help(c); 
        if (!result.empty()){
            std::cout << " " << result;
        }
    }
}

int main(){
    auto accounting = std::make_shared<AccountsHelper>();
    auto billing = std::make_shared<PaymentsHelper>();
    auto repairs = std::make_shared<RepairHelper>();
    accounting->setNext(billing)->setNext(repairs);

    std::cout << "Chain of command: Acccounting > Payments > Repairs \n\n";
    clientRequests(accounting);
    return 0;
}

