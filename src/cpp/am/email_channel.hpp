#pragma once

#include "notification_channel.hpp"
#include <iostream>
#include <string>

class EmailChannel : public NotificationChannel
{
public:
	EmailChannel(const std::string &recipient_email) : _recipient_email(recipient_email) {}

	virtual ~EmailChannel() = default;

	// Sends an email notification with the given title and body
	virtual void send_notification(const std::string &title, const std::string &body) const override
	{
		// Here, you would normally use an email library to send the email.
		// For this example, we'll just print the email to the console.
		std::cout << "Sending email to " << _recipient_email << '\n';
		std::cout << "Title: " << title << '\n';
		std::cout << "Body: " << body << '\n';
	}

private:
	std::string _recipient_email;
};
