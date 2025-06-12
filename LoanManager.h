#ifndef LOANMANAGER_H
#define LOANMANAGER_H

#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include "Loan.h"
#include "User.h"
#include "Resource.h"

class LoanManager {
public:
    LoanManager() = default;
    ~LoanManager() = default;

    void issueLoan(std::shared_ptr<User> user, std::shared_ptr<Resource> resource);
    void returnLoan(const std::string &loanId);
    void renewLoan(const std::string &loanId);
    std::vector<std::shared_ptr<Loan>> getActiveLoansForUser(const std::string &userId) const;

private:
    std::vector<std::shared_ptr<Loan>> m_loans;
};

#endif // LOANMANAGER_H
