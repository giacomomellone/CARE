#include "../alerting_module.hpp"
#include "../alert_criteria.hpp"
#include "../risk_data.hpp"
#include "../alert_template.hpp"
#include "gtest/gtest.h"

// Test the functionality of AlertCriteria
TEST(AlertCriteriaTest, MeetsCriteria)
{
	AlertCriteria criteria(50.0, 3);
	RiskData data1(60.0, "Location1", "Details1");
	RiskData data2(40.0, "Location2", "Details2");

	ASSERT_TRUE(criteria.meets_criteria(data1));
	ASSERT_FALSE(criteria.meets_criteria(data2));
}

// Test the functionality of AlertTemplate
TEST(AlertTemplateTest, FormatAlert)
{
	AlertTemplate template1("High Alert", "High risk detected", 3);
	std::string location = "Location1";
	std::string details = "Details1";

	ASSERT_EQ(template1.format_title(location), "Location: Location1 - High Alert");
	ASSERT_EQ(template1.format_body(details), "High risk detected\nDetails: Details1");
}

// Test the AlertingModule with Mock Channel
class MockChannel : public NotificationChannel
{
public:
	void send_notification(const std::string &title, const std::string &body) const override
	{
		// You can implement logic to capture the title and body for later validation
	}
};

TEST(AlertingModuleTest, TriggerAlert)
{
	AlertingModule module;
	module.initialize();

	// Add a mock channel to capture the alert notification
	MockChannel mockChannel;
	module.add_channel(&mockChannel);

	// Trigger an alert with a risk value that meets the criteria
	RiskData data(60.0, "Location1", "Details1");
	module.trigger_alert(data);

	// Validate that the mock channel received the expected alert
	// You may need to implement additional logic within MockChannel to capture and validate the alert
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
