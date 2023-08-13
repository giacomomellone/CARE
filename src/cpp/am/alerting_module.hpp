#pragma once

#include "alert_criteria.hpp"
#include "alert_template.hpp"
#include "notification_channel.hpp"
#include "risk_data.hpp"

#include <vector>

class AlertingModule
{
public:
	AlertingModule();
	~AlertingModule();

	void initialize();
	void add_channel(NotificationChannel *channel); // Allows adding notification channels
	void trigger_alert(const RiskData &data);
	RiskData fetch_data();
	void run();

private:
	// Containers to hold your alert criteria, templates, and notification channels
	std::vector<AlertCriteria> _criteria;
	std::vector<AlertTemplate> _templates;
	std::vector<NotificationChannel *> _channels; // Uses the NotificationChannel interface
};
