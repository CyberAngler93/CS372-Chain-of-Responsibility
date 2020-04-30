// Created by Matt Perry
// This is a headerfile for a chain of responisbility example
// 4/29/2020

#ifndef HELPER_HPP
#define HELPER_HPP
#include <memory>
#include <iostream>

class HelpDesk {
public:
    virtual ~HelpDesk() = default;
    virtual std::shared_ptr<HelpDesk> setNext(std::shared_ptr<HelpDesk> helper) = 0;
    virtual std::string Help(std::string request) = 0;

};

class AbstractHelpDesk : public HelpDesk {
public:
    AbstractHelpDesk() : _nextHelper(std::shared_ptr<HelpDesk>(nullptr)){}
    std::shared_ptr<HelpDesk> setNext(std::shared_ptr<HelpDesk> helper) override {
        this->_nextHelper = helper;
        return helper;
    }
    std::string Help(std::string request) override {
        if (this->_nextHelper){
            return this->_nextHelper->Help(request);
        }
        return {};
    }
private:
    std::shared_ptr<HelpDesk> _nextHelper;
};

class AccountsHelper : public AbstractHelpDesk {
public:
    std::string Help(std::string request) override {
        if(request == "Accounting") {
            return "I will transfer you to Accouting Help desk now: " + request + ".\n";
        }
        else{
            return AbstractHelpDesk::Help(request);
        }
    }
};

class PaymentsHelper : public AbstractHelpDesk {
public:
    std::string Help(std::string request) override {
        if(request == "Payments") {
            return "I will transfer you to Payments Help desk now: " + request + ".\n";
        }
        else{
            return AbstractHelpDesk::Help(request);
        }
    }
};

class RepairHelper : public AbstractHelpDesk {
public:
    std::string Help(std::string request) override {
        if(request == "Repairs") {
            return "I will transfer you to Repairs Help desk now: " + request + ".\n";
        }
        else{
            return AbstractHelpDesk::Help(request);
        }
    }
};


#endif