#include "ResourceManager.h"
#include <stdexcept>
#include <algorithm>

void ResourceManager::addResource(std::shared_ptr<Resource> resource) {
    m_resources.push_back(resource);
}

void ResourceManager::removeResource(const std::string &resourceId) {
    auto it = std::remove_if(m_resources.begin(), m_resources.end(),
        [&resourceId](const std::shared_ptr<Resource> &res) {
            return res->getId() == resourceId;
        });
    if (it != m_resources.end()) {
        m_resources.erase(it, m_resources.end());
    } else {
        throw std::runtime_error("Resource with ID not found: " + resourceId);
    }
}

std::shared_ptr<Resource> ResourceManager::findResourceById(const std::string &resourceId) const {
    auto it = std::find_if(m_resources.begin(), m_resources.end(),
        [&resourceId](const std::shared_ptr<Resource> &res) {
            return res->getId() == resourceId;
        });
    if(it != m_resources.end()) {
        return *it;
    }
    return nullptr; // Not found
}

std::vector<std::shared_ptr<Resource>> ResourceManager::searchResourcesByTitle(const std::string &title) const {
    std::vector<std::shared_ptr<Resource>> results;
    for(const auto &res : m_resources) {
        if(res->getTitle().find(title) != std::string::npos) {
            results.push_back(res);
        }
    }
    return results;
}

std::vector<std::shared_ptr<Resource>> ResourceManager::getAllResources() const {
    return m_resources;
}

void ResourceManager::updateResource(std::shared_ptr<Resource> updatedResource) {
    auto it = std::find_if(m_resources.begin(), m_resources.end(),
        [&updatedResource](const std::shared_ptr<Resource> &res) {
            return res->getId() == updatedResource->getId();
        });
    if(it != m_resources.end()) {
        *it = updatedResource;
    } else {
        throw std::runtime_error("Resource to update not found: " + updatedResource->getId());
    }
}
