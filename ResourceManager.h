#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include "Resource.h"

class ResourceManager {
public:
    ResourceManager() = default;
    ~ResourceManager() = default;

    void addResource(std::shared_ptr<Resource> resource);
    void removeResource(const std::string &resourceId);
    std::shared_ptr<Resource> findResourceById(const std::string &resourceId) const;
    std::vector<std::shared_ptr<Resource>> searchResourcesByTitle(const std::string &title) const;
    std::vector<std::shared_ptr<Resource>> getAllResources() const;

    void updateResource(std::shared_ptr<Resource> updatedResource);

private:
    std::vector<std::shared_ptr<Resource>> m_resources;
};

#endif // RESOURCEMANAGER_H
