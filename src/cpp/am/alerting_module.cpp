#include "alerting_module.hpp"
#include "email_channel.hpp"
#include "log_util.hpp"
#include "risk_data.hpp"

#include <thread>
#include <chrono>
#include <memory>

AlertingModule::AlertingModule() {}

AlertingModule::~AlertingModule() {}

void AlertingModule::initialize()
{
	// Initialize some example alert criteria with corresponding severity levels
	_criteria.push_back(AlertCriteria(75.0, 3));
	_criteria.push_back(AlertCriteria(50.0, 2));

	// Initialize some example alert templates with severity levels
	_templates.push_back(AlertTemplate("High Alert", "High risk detected", 3));
	_templates.push_back(AlertTemplate("Medium Alert", "Moderate risk detected", 2));
}

void AlertingModule::add_channel(NotificationChannel *channel)
{
	_channels.push_back(channel); // Adds a notification channel
}

void AlertingModule::trigger_alert(const RiskData &data)
{
	for (const auto &criteria : _criteria)
	{
		if (criteria.meets_criteria(data))
		{
			// Find the corresponding template by severity
			const AlertTemplate *alert_template = nullptr;
			for (const auto &defined_template : _templates)
			{
				if (defined_template.get_severity() == criteria.get_severity())
				{
					alert_template = &defined_template;
					break;
				}
			}

			if (alert_template)
			{
				std::string title = alert_template->format_title(data.get_location());
				std::string body = alert_template->format_body(data.get_details());

				// Send alert through each channel
				for (const auto &channel : _channels)
				{
					channel->send_notification(title, body);
				}
			}
			else
			{
				LogUtil::log(LogLevel::ERROR, "No corresponding template found for severity: " + std::to_string(criteria.get_severity()));
			}
		}
	}
}

RiskData AlertingModule::fetch_data()
{
	// Simulating fetching risk data from some data source
	// TODO: Replace this with actual logic to retrieve risk data

	double sample_risk_value = 50.0; // Example risk value
	std::string sample_location = "Sample Location";
	std::string sample_details = "Sample Details";

	return RiskData(sample_risk_value, sample_location, sample_details);
}

void AlertingModule::run()
{
	// Continuous loop to evaluate and trigger alerts
	while (true)
	{
		RiskData data = fetch_data(); // Implement this function to fetch the latest risk data
		trigger_alert(data);

		// You may want to add some sleep or delay here to control how often you check the alerts
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
