#include "LoanManager.h"
#include <stdexcept>

void LoanManager::issueLoan(std::shared_ptr<User> user, std::shared_ptr<Resource> resource) {
    if (!resource->isAvailable()) {
        throw std::runtime_error("Resource is not available for loan.");
    }

    resource->borrowResource();

    auto loan = std::make_shared<Loan>(resource, user);
    m_loans.push_back(loan);

    // Add loan to user's current loans
    user->borrowResource(resource);
}

void LoanManager::returnLoan(const std::string &loanId) {
    auto it = std::find_if(m_loans.begin(), m_loans.end(),
                           [&loanId](const std::shared_ptr<Loan> &loan) {
                               return loan->getLoanId() == loanId;
                           });
    if (it == m_loans.end()) {
        throw std::runtime_error("Loan ID not found.");
    }

    auto loan = *it;
    loan->closeLoan();
    loan->getResource()->returnResource();

    // Remove the loan from user's current loans
    auto user = loan->getUser();
    user->returnResource(loan->getResource());

    m_loans.erase(it);
}

void LoanManager::renewLoan(const std::string &loanId) {
    auto it = std::find_if(m_loans.begin(), m_loans.end(),
                           [&loanId](const std::shared_ptr<Loan> &loan) {
                               return loan->getLoanId() == loanId;
                           });
    if (it == m_loans.end()) {
        throw std::runtime_error("Loan ID not found.");
    }
    (*it)->extendDueDate();
}

std::vector<std::shared_ptr<Loan>> LoanManager::getActiveLoansForUser(const std::string &userId) const {
    std::vector<std::shared_ptr<Loan>> result;
    for (const auto &loan : m_loans) {
        if (loan->getUser()->getUserId() == userId && !loan->isReturned()) {
            result.push_back(loan);
        }
    }
    return result;
}
