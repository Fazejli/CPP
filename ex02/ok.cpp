#include "Account.hpp"

Account::static int   _nbAccounts = 0;
Account::static int	_totalAmount = 0;
Account::static int	_totalNbDeposits = 0;
Account::static int	_totalNbWithdrawals = 0;

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
    std::cout << "created" << std::ednl;
}

//Destructeur (message de fermeture)
Account::~Account(void){
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::ednl;
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
    std::cout << ";deposits:" << deposit;
    std::cout << ";amount:" << _amount;
    std::cout << ";nb_deposits:" << _nbDeposits;
    std::cout << std::endl;
}

//Verifier si amount >= 50 (oui return true et non return false)
bool	Account::makeWithdrawal( int withdrawal );
int		Account::checkAmount( void ) const;
void	Account::displayStatus( void ) const;


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
