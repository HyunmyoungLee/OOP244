#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H
#define SIZE 20

namespace sict{
	class Contact{
		char Name[SIZE];
		long long* PhoneNumber;
		int Count;
		public:
			Contact();
			Contact(const char*, const long long*, int);
		        ~Contact();
			bool isEmpty() const;
			void display() const;
	};
}
#endif
