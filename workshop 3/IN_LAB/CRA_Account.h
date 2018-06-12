#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H


namespace sict{
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account{
		private:
			char FamilyName[max_name_length];
			char GivenName[max_name_length];
			int SIN;

		public:
			void set(const char* familyName, const char* givenName, int sin);
			bool isEmpty() const;
			void display() const;
	};
}

#endif
