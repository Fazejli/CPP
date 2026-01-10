#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(){
    return(_nbAccounts);
}

int	Account::getTotalAmount(){
    return (_totalAmount);
}

int  Account::getNbDeposits(){
    return(_totalNbDeposits);
}

int  Account::getNbWithdrawals(){
    return (_totalNbWithdrawals);
}

void Account::_displayTimestamp(void) {
    // Pour l'instant, tu peux mettre un timestamp fixe
    std::cout << "[19920104_091532] ";
    
    // OU utiliser le vrai timestamp (plus avancé):
    /*
    time_t now = time(0);
    tm* ltm = localtime(&now);
    std::cout << "[" 
              << 1900 + ltm->tm_year
              << (ltm->tm_mon + 1 < 10 ? "0" : "") << ltm->tm_mon + 1
              << (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday
              << "_"
              << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour
              << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min
              << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec
              << "]";
    */
}

//Constructeur (init + maj var.statiques)
Account::Account(int initial_deposit){
    _amount = initial_deposit;
    _accountIndex = _nbAccounts;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _nbAccounts++;
    _totalAmount += _amount;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;
}

//Destructeur (message de fermeture)
Account::~Account(void){
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
}

//Faire un depot (Avant/apres + maj compteurs)
void	Account::makeDeposit( int deposit ){
    int previous_amount = _amount;

    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << previous_amount;
    std::cout << ";deposit:" << deposit;
    std::cout << ";amount:" << _amount;
    std::cout << ";nb_deposits:" << _nbDeposits;
    std::cout << std::endl;
}

//Verifier si amount >= 50 (oui return true et non return false)
bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    if (_amount - withdrawal < 0)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal;
    std::cout << ";amount:" << _amount;
    std::cout << ";nb_withdrawals:" << _nbWithdrawals;
    std::cout << std::endl;
    return (true);
}
int		Account::checkAmount( void ) const{
    return _amount;
}

void	Account::displayStatus( void ) const{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";deposits:" << _nbDeposits;
    std::cout << ";withdrawals:" << _nbWithdrawals;
    std::cout << std::endl;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts;
    std::cout << ";total:" << _totalAmount;
    std::cout << ";deposits:" << _totalNbDeposits;
    std::cout << ";withdrawals:" << _totalNbWithdrawals;
    std::cout << std::endl;
}
