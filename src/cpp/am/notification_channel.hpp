#pragma once

#include <string>

class NotificationChannel {
public:
  virtual ~NotificationChannel() = default;

  // Sends a notification with the given title and body
  virtual void send_notification(const std::string& title, const std::string& body) const = 0;
};
