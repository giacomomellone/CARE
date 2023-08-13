#include "alerting_module.hpp"
#include "email_channel.hpp"
#include "log_util.hpp"
#include "risk_data.hpp"

int main()
{
    AlertingModule alerting_module;

    // Initialize the alerting module with criteria, templates
    alerting_module.initialize();

    // Create specific channels
    NotificationChannel *email_channel = new EmailChannel("giacomo.mellone@example.com");

    // Add channels to the alerting module
    alerting_module.add_channel(email_channel);

    // Run the alerting module to continuously evaluate and trigger alerts
    alerting_module.run();

    // Clean up allocated resources
    delete email_channel;

    return 0;
}
