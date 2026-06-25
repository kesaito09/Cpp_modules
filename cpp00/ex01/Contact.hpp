#ifndef CONTACT_H_
#define CONTACT_H_
#include <string>

class Contact {
 public:
  struct ContactData {
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string secret;
  };

  void Set(const ContactData& data);
  static bool IsEmptyField(const std::string& field);
  static bool ValidateFormat(const ContactData& data);
  static std::string FormatField(const std::string& field);
  static void DisplayHeader(void);
  void DisplayRow(int index) const;
  void DisplayDetails(void) const;

 private:
  ContactData data_;
};

#endif
