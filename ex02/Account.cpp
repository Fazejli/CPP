#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit):
    : _accountIndex(_nbAccounts),
    _amount(initial_deposit);
    _nbDeposits(0);
    _nbWithdrawals(0) {
    
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";created" << std::endl;
}
Account::~Account(void){
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";closed" << std::endl;
}
static int	Account::getNbAccounts(){
    return(_nbAccounts);
}

static int	Account::getTotalAmount(){
    return (_totalAmount);
}

static int  Account::getNbDeposits(){
    return(_totalNbDeposits);
}

static int  Account::getNbWithdrawals(){
    return (_totalNbWithdrawals);
}

void    Account::displayAccountsInfos(){
    _displayTimestamp();
    std::cout << "accounts:" << Account._nbAccounts;
    std::cout << ";total:" << Account._totalAmount;
    std::cout << ";deposits:" << Account._totalNbDeposits;
    std::cout << ";withdrawal:" << Account._totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ){
    int previous_amount = _amount;

    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << previous_amount;
    std::cout << ";deposits:" << deposit;
    std::cout << ";amount:" << _amount;
    std::cout << ";nb_deposits:" << _nbDeposits;
    std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal );
int		Account::checkAmount( void ) const;
void	Account::displayStatus( void ) const;

