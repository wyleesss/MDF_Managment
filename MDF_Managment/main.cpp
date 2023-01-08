#include "extedned_classes.h"
using namespace std;

void console_set_max_size_parameters(int& width, int& length, int& height, int width_length_minimal_parameter = 100, int height_minimal_parameter = 1)
{
	system("cls");
	cout << "Õ¿À¿ÿ“”¬¿ÕÕﬂ œ–Œ√–¿Ã»\n!‰‡Ì≥ ÁÏ≥ÌËÚË ·Û‰Â ÌÂÏÓÊÎË‚Ó\n!‰ÓÚËÏÛÈÚÂÒ¸ ‚ËÏÓ„ ˘Ó‰Ó ‚‚Â‰ÂÌÌˇ ‰‡ÌËı\n\n";
	system("pause");

	do 
	{
		//ˇÍ˘Ó ‚‚Â‰ÂÌÓ ÌÂÔ‡‚ËÎ¸ÌËÈ ÚËÔ ‰‡ÌËı
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		system("cls");
		cout << "Õ¿À¿ÿ“”¬¿ÕÕﬂ œ–Œ√–¿Ã»\n!‰‡Ì≥ ÁÏ≥ÌËÚË ·Û‰Â ÌÂÏÓÊÎË‚Ó\n!‰ÓÚËÏÛÈÚÂÒ¸ ‚ËÏÓ„ ˘Ó‰Ó ‚‚Â‰ÂÌÌˇ ‰‡ÌËı\n\n"
			"‚‚Â‰≥Ú¸ Ï‡ÍÒËÏ‡Î¸ÌÓ ÏÓÊÎË‚Û ¯ËËÌÛ Ãƒ‘ ‚ ÏÏ (ÌÂ ÏÂÌ¯Â Ì≥Ê " << width_length_minimal_parameter << ")"
			    "\n-> ";
	} while (!(cin >> width) || width < width_length_minimal_parameter);

	do
	{
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		system("cls");
		cout << "Õ¿À¿ÿ“”¬¿ÕÕﬂ œ–Œ√–¿Ã»\n!‰‡Ì≥ ÁÏ≥ÌËÚË ·Û‰Â ÌÂÏÓÊÎË‚Ó\n!‰ÓÚËÏÛÈÚÂÒ¸ ‚ËÏÓ„ ˘Ó‰Ó ‚‚Â‰ÂÌÌˇ ‰‡ÌËı\n\n"
			"‚‚Â‰≥Ú¸ Ï‡ÍÒËÏ‡Î¸ÌÓ ÏÓÊÎË‚Û ‰Ó‚ÊËÌÛ Ãƒ‘ ‚ ÏÏ (ÌÂ ÏÂÌ¯Â Ì≥Ê " << width_length_minimal_parameter << ")"
			    "\n-> ";
	} while (!(cin >> length) || length < width_length_minimal_parameter);

	do
	{
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		system("cls");
		cout << "Õ¿À¿ÿ“”¬¿ÕÕﬂ œ–Œ√–¿Ã»\n!‰‡Ì≥ ÁÏ≥ÌËÚË ·Û‰Â ÌÂÏÓÊÎË‚Ó\n!‰ÓÚËÏÛÈÚÂÒ¸ ‚ËÏÓ„ ˘Ó‰Ó ‚‚Â‰ÂÌÌˇ ‰‡ÌËı\n\n"
			"‚‚Â‰≥Ú¸ Ï‡ÍÒËÏ‡Î¸ÌÓ ÏÓÊÎË‚Û ÚÓ‚˘ËÌÛ Ãƒ‘ ‚ ÏÏ (ÌÂ ÏÂÌ¯Â Ì≥Ê " << height_minimal_parameter << ")"
			   "\n-> ";
	}
	while (!(cin >> height) || height < height_minimal_parameter);
	system("cls");
}

MDF console_set_mdf_parameters()
{
	string mdf_name = "";
	double mdf_price = NULL;
	int mdf_width = NULL, mdf_length = NULL, mdf_height = NULL;

	system("cls");
	cout << "¬¬≈ƒ≤“‹ ¬≤ƒŒÃŒ—“≤ ŸŒƒŒ Ãƒ‘\n\n"
		"‚‚Â‰≥Ú¸ Ì‡Á‚Û Ãƒ‘"
		"\n-> ";
	cin >> mdf_name;

	do
	{
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		system("cls");
		cout << "¬¬≈ƒ≤“‹ ¬≤ƒŒÃŒ—“≤ ŸŒƒŒ Ãƒ‘\n\n"
			"‚‚Â‰≥Ú¸ ‚‡Ú≥ÒÚ¸ Ãƒ‘"
			"\n-> ";
	} while (!(cin >> mdf_price) || mdf_price < 0);

	do
	{
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		system("cls");
		cout << "¬¬≈ƒ≤“‹ ¬≤ƒŒÃŒ—“≤ ŸŒƒŒ Ãƒ‘\n\n"
			"‚‚Â‰≥Ú¸ ¯ËËÌÛ Ãƒ‘ ‚ ÏÏ"
			"\n-> ";
	} while (!(cin >> mdf_width) || mdf_width < 1);

	do
	{
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		system("cls");
		cout << "¬¬≈ƒ≤“‹ ¬≤ƒŒÃŒ—“≤ ŸŒƒŒ Ãƒ‘\n\n"
			"‚‚Â‰≥Ú¸ ‰Ó‚ÊËÌÛ Ãƒ‘ ‚ ÏÏ"
			"\n-> ";
	} while (!(cin >> mdf_length) || mdf_length < 1);

	do
	{
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		system("cls");
		cout << "¬¬≈ƒ≤“‹ ¬≤ƒŒÃŒ—“≤ ŸŒƒŒ Ãƒ‘\n\n"
			"‚‚Â‰≥Ú¸ ÚÓ‚˘ËÌÛ Ãƒ‘ ‚ ÏÏ"
			"\n-> ";
	} while (!(cin >> mdf_height) || mdf_height < 1);

	system("cls");

	return MDF(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout.precision(5);

	bool exit = false;
	int user_choice = NULL;
	string mdf_name = "";
	double mdf_price = NULL;
	int mdf_width = NULL, mdf_length = NULL, mdf_height = NULL, party_amount = NULL, 
		storage_max_size = NULL,
		percentage = NULL;
	do
	{
		//ˇÍ˘Ó ‚‚Â‰ÂÌÓ ÌÂÔ‡‚ËÎ¸ÌËÈ ÚËÔ ‰‡ÌËı
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		system("cls");
		cout << "œ–Œ√–¿Ã¿ ƒÀﬂ Œ¡À≤ ” Ãƒ‘ Õ¿ — À¿ƒ≤"
			"\n\n‚‚Â‰≥Ú¸:"
			"\n1 - ‰Îˇ Ó·Î≥ÍÛ Á‡ ‚‡Ú≥ÒÚ˛ Ãƒ‘"
			"\n2 - ‰Îˇ Ó·Î≥ÍÛ Á‡ ÓÁÏ≥ÓÏ Ãƒ‘"
			"\n0 - ‰Îˇ ‚ËıÓ‰Û Á ÔÓ„‡ÏË"
			"\n-> ";
	} while (!(cin >> user_choice) || user_choice < 0 || user_choice > 2);

	
	if (user_choice == 1)
	{

		console_set_max_size_parameters(mdf_width, mdf_length, mdf_height);
		CostStorage proccess(mdf_width, mdf_length, mdf_height);
		while (!exit)
		{
			do
			{
				if (!cin.good())
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
				system("cls");
				cout << "Œ¡À≤  Ãƒ‘ Õ¿ — À¿ƒ≤ «¿ ¬¿–“≤—“ﬁ\n";
				proccess.cout_info();
				cout << "\n\n‚‚Â‰≥Ú¸:"
					"\n1 - ‰Îˇ ÛÔ‡‚Î≥ÌÌˇ ÒÍÎ‡‰ÓÏ"
					"\n2 - ‰Îˇ ‚≥‰Ó·‡ÊÂÌÌˇ ‰ÂÚ‡Î¸ÌÓø ≥ÌÙÓÏ‡ˆ≥ø"
					"\n0 - ‰Îˇ ‚ËıÓ‰Û Á ÔÓ„‡ÏË"
					"\n-> ";
			} while (!(cin >> user_choice) || user_choice < 0 || user_choice > 3);

			switch (user_choice)
			{
			case 1:

				do
				{
					if (!cin.good())
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
					}
					system("cls");
					cout << "Œ¡À≤  Ãƒ‘ Õ¿ — À¿ƒ≤ «¿ ¬¿–“≤—“ﬁ"
						"\n\n‚‚Â‰≥Ú¸:"
						"\n1 - ‰Îˇ Â∫ÒÚ‡ˆø Ì‡‰ıÓ‰ÊÂÌÌˇ ÌÓ‚Óø Ô‡Ú≥ø Ãƒ‘ Ì‡ ÒÍÎ‡‰"
						"\n2 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÂÂ‰‡˜≥ Ãƒ‘ Á≥ ÒÍÎ‡‰Û Ì‡ ‚ËÓ·ÌËˆÚ‚Ó"
						"\n3 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÓ‚ÂÌÂÌÌˇ Ãƒ‘ Á ‚ËÓ·ÌËˆÚ‚‡ Ì‡ ÒÍÎ‡‰"
						"\n0 - ‰Îˇ ‚≥‰Ï≥ÌË"
						"\n-> ";
				} while (!(cin >> user_choice) || user_choice < 0 || user_choice > 3);

				switch (user_choice)
				{
				case 1:

					do
					{
						if (!cin.good())
						{
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						system("cls");
						cout << "¬¬≈ƒ≤“‹ ¬≤ƒŒÃŒ—“≤ ŸŒƒŒ œ¿–“≤Ø\n\n"
							"‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ ¯ÚÛÍ Ãƒ‘"
							"\n-> ";
					} while (!(cin >> party_amount) || party_amount < 1);
					proccess.new_arrival(console_set_mdf_parameters(), party_amount);
					system("pause");
					break;

				case 2:

					do
					{
						if (!cin.good())
						{
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						system("cls");
						cout << "Œ¡À≤  Ãƒ‘ Õ¿ — À¿ƒ≤ «¿ ¬¿–“≤—“ﬁ"
							"\n\n‚‚Â‰≥Ú¸:"
							"\n1 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÓÒÚÓø ÔÂÂ‰‡˜≥ ÎËÒÚ≥‚ (Á ‚Â¯ËÌË ÒÚÓÒÛ)"
							"\n2 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÂÂ‰‡˜≥ ÎËÒÚ≥‚ Á ÔÂ‚ÌËÏË ‚Î‡ÒÚË‚ÓÒÚˇÏË (ÔÂÂ·Ë‡˛˜Ë ÒÚÓÒ)"
							"\n0 - ‰Îˇ ‚≥‰Ï≥ÌË"
							"\n-> ";
					} while (!(cin >> user_choice) || user_choice < 0 || user_choice > 2);

					switch (user_choice)
					{

					case 1:
						do
						{
							if (!cin.good())
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
							}
							system("cls");
							cout << "Œ¡À≤  Ãƒ‘ Õ¿ — À¿ƒ≤ «¿ ¬¿–“≤—“ﬁ"
								"\n\n‚‚Â‰≥Ú¸:"
								"\n1 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÂÂ‰‡˜≥ ‚Ò≥ı ÎËÒÚ≥‚ Á ‚Â¯ËÌË ÒÚÓÒÛ"
								"\n2 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÂÂ‰‡˜≥ Ú≥Î¸ÍË Ó·≥Á‡ÌËı ÎËÒÚ≥‚ Á ‚Â¯ËÌË ÒÚÓÒÛ"
								"\n3 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÂÂ‰‡˜≥ Ú≥Î¸ÍË ˆ≥ÎËı ÎËÒÚ≥‚ Á ‚Â¯ËÌË ÒÚÓÒÛ"
								"\n0 - ‰Îˇ ‚≥‰Ï≥ÌË"
								"\n-> ";
						} while (!(cin >> user_choice) || user_choice < 0 || user_choice > 3);

						switch (user_choice)
						{
						case 1:
							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ œ¿–“≤Ø"
									"\n\n‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ Ãƒ‘"
									"\n-> ";
							} while (!(cin >> party_amount) || party_amount < 1);
							system("cls");
							proccess.put_into_production_top(party_amount);
							system("pause");
							break;

						case 2:
							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ œ¿–“≤Ø"
									"\n\n‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ Ãƒ‘"
									"\n-> ";
							} while (!(cin >> party_amount) || party_amount < 1);
							system("cls");
							proccess.put_into_production_cut(party_amount);
							system("pause");
							break;

						case 3:
							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ œ¿–“≤Ø"
									"\n\n‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ Ãƒ‘"
									"\n-> ";
							} while (!(cin >> party_amount) || party_amount < 1);
							system("cls");
							proccess.put_into_production_whole(party_amount);
							system("pause");
							break;

						default:
							break;
						}
						break;

					case 2:
						do
						{
							if (!cin.good())
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
							}
							system("cls");
							cout << "Œ¡À≤  Ãƒ‘ Õ¿ — À¿ƒ≤ «¿ ¬¿–“≤—“ﬁ"
								"\n\n‚‚Â‰≥Ú¸:"
								"\n1 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÂÂ‰‡˜≥ ÎËÒÚ≥‚ Á‡ ÓÁÏ≥ÓÏ"
								"\n2 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÂÂ‰‡˜≥ ÎËÒÚ≥‚ Á‡ ˆ≥ÌÓ˛"
								"\n3 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÂÂ‰‡˜≥ ÎËÒÚ≥‚ Á‡ Ì‡Á‚Ó˛"
								"\n4 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÂÂ‰‡˜≥ ÎËÒÚ≥‚ ≥ Á‡ ÓÁÏ≥ÓÏ, ≥ Á‡ ˆ≥ÌÓ˛, ≥ Á‡ Ì‡Á‚Ó˛"
								"\n0 - ‰Îˇ ‚≥‰Ï≥ÌË"
								"\n-> ";
						} while (!(cin >> user_choice) || user_choice < 0 || user_choice > 4);

						switch (user_choice)
						{
						case 1:

							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ Ãƒ‘"
									"\n\n‚‚Â‰≥Ú¸ ¯ËËÌÛ Ãƒ‘ ‚ ÏÏ"
									"\n-> ";
							} while (!(cin >> mdf_width) || mdf_width < 1);

							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ Ãƒ‘"
									"\n\n‚‚Â‰≥Ú¸ ‰Ó‚ÊËÌÛ Ãƒ‘ ‚ ÏÏ"
									"\n-> ";
							} while (!(cin >> mdf_length) || mdf_length < 1);

							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ Ãƒ‘"
									"\n\n‚‚Â‰≥Ú¸ ÚÓ‚˘ËÌÛ Ãƒ‘ ‚ ÏÏ"
									"\n-> ";
							} while (!(cin >> mdf_height) || mdf_height < 1);

							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ œ¿–“≤Ø"
									"\n\n‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ Ãƒ‘"
									"\n-> ";
							} while (!(cin >> party_amount) || party_amount < 1);
							system("cls");
							proccess.put_into_production_special_size(mdf_width, mdf_length, mdf_height, party_amount);
							system("pause");
							break;

						case 2:

							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ Ãƒ‘"
									"\n\n‚‚Â‰≥Ú¸ ˆ≥ÌÛ Ãƒ‘"
									"\n-> ";
							} while (!(cin >> mdf_price) || mdf_price < 0);

							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ œ¿–“≤Ø"
									"\n\n‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ Ãƒ‘"
									"\n-> ";
							} while (!(cin >> party_amount) || party_amount < 1);
							system("cls");
							proccess.put_into_production_special_price(mdf_price, party_amount);
							system("pause");
							break;

						case 3:

							system("cls");
							cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ Ãƒ‘"
								"\n\n‚‚Â‰≥Ú¸ Ì‡Á‚Û Ãƒ‘"
								"\n-> ";
							cin >> mdf_name;

							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ œ¿–“≤Ø"
									"\n\n‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ Ãƒ‘"
									"\n-> ";
							} while (!(cin >> party_amount) || party_amount < 1);
							system("cls");
							proccess.put_into_production_special_name(mdf_name, party_amount);
							system("pause");
							break;

						case 4:

							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ œ¿–“≤Ø"
									"\n\n‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ Ãƒ‘"
									"\n-> ";
							} while (!(cin >> party_amount) || party_amount < 1);
							system("cls");
							proccess.put_into_production_special(console_set_mdf_parameters(), party_amount);
							system("pause");
							break;

						default:
							break;

						}

						break;

					default:
						break;
					}

					break;
				case 3:

					do
					{
						if (!cin.good())
						{
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						system("cls");
						cout << "Œ¡À≤  Ãƒ‘ Õ¿ — À¿ƒ≤ «¿ ¬¿–“≤—“ﬁ"
							"\n\n‚‚Â‰≥Ú¸:"
							"\n1 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÓ‚ÂÌÂÌÌˇ Ó·≥ÁÍ≥‚ Á≥ ÒÍÎ‡‰Û"
							"\n2 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÓ‚ÂÌÂÌÌˇ ˆ≥ÎËı ÎËÒÚ≥‚ Á≥ ÒÍÎ‡‰Û"
							"\n0 - ‰Îˇ ‚≥‰Ï≥ÌË"
							"\n-> ";
					} while (!(cin >> user_choice) || user_choice < 0 || user_choice > 2);

					switch (user_choice)
					{

					case 1:
						do
						{
							if (!cin.good())
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
							}
							system("cls");
							cout << "¬¬≈ƒ≤“‹ ¬≤ƒŒÃŒ—“≤ ŸŒƒŒ œŒ¬≈–Õ≈ÕÕﬂ\n\n"
								"‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ ¯ÚÛÍ Ãƒ‘"
								"\n-> ";
						} while (!(cin >> party_amount) || party_amount < 1);

						proccess.return_from_production_cut(console_set_mdf_parameters(), party_amount);
						system("pause");
						break;

					case 2:
						do
						{
							if (!cin.good())
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
							}
							system("cls");
							cout << "¬¬≈ƒ≤“‹ ¬≤ƒŒÃŒ—“≤ ŸŒƒŒ œŒ¬≈–Õ≈ÕÕﬂ\n\n"
								"‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ ¯ÚÛÍ Ãƒ‘"
								"\n-> ";
						} while (!(cin >> party_amount) || party_amount < 1);

						do
						{
							if (!cin.good())
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
							}
							system("cls");
							cout << "¬¬≈ƒ≤“‹ ¬≤ƒŒÃŒ—“≤ ŸŒƒŒ œŒ¬≈–Õ≈ÕÕﬂ\n\n"
								"‚‚Â‰≥Ú¸ ‚≥‰ÒÓÚÓÍ ÁÌËÊÂÌÌˇ ‚‡ÚÓÒÚ≥ Ãƒ‘"
								"\n-> ";
						} while (!(cin >> percentage) || percentage < 0);

						proccess.return_from_production_whole(console_set_mdf_parameters(), party_amount, percentage);
						system("pause");
						break;

					default:
						break;
					}
					break;

				default:
					break;
				}

				break;

			case 2:

				system("cls");
				cout << "Œ¡À≤  Ãƒ‘ Õ¿ — À¿ƒ≤ «¿ ¬¿–“≤—“ﬁ\n";
				proccess.cout_detail_info();
				cout << "\n\n";
				system("pause");
				break;

			default:

				do
				{
					if (!cin.good())
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
					}
					system("cls");
					cout << "Œ¡À≤  Ãƒ‘ Õ¿ — À¿ƒ≤ «¿ ¬¿–“≤—“ﬁ\n\n";
					cout << "‚Ë ‰≥ÈÒÌÓ ıÓ˜ÂÚÂ ‚ËÈÚË Á ÔÓ„‡ÏË?"
						"\n1 - Ì≥"
						"\n0 - Ú‡Í"
						"\n-> ";
				} while (!(cin >> user_choice) || user_choice < 0 || user_choice > 3);

				exit = !user_choice;
				break;
			}
		}

	}

	//ÍÓ‰ Ï‡ÈÊÂ ≥‰ÂÌÚË˜ÌËÈ, ÁÌ‡˜ÌËı ‚≥‰Ï≥ÌÌÓÒÚÂÈ ÌÂÏ‡∫
	if (user_choice == 2)
	{

		console_set_max_size_parameters(mdf_width, mdf_length, mdf_height);
		//‰Ó‰‡ÚÍÓ‚Ó Á‡ÔËÚÛ∫ÏÓ Ï‡ÍÒËÏ‡Î¸ÌÛ Ï≥ÒÚÍ≥ÒÚ¸ ÒÍÎ‡‰Û
		do
		{
			if (!cin.good())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			system("cls");
			cout << "Õ¿À¿ÿ“”¬¿ÕÕﬂ œ–Œ√–¿Ã»\n!‰‡Ì≥ ÁÏ≥ÌËÚË ·Û‰Â ÌÂÏÓÊÎË‚Ó\n!‰ÓÚËÏÛÈÚÂÒ¸ ‚ËÏÓ„ ˘Ó‰Ó ‚‚Â‰ÂÌÌˇ ‰‡ÌËı\n\n"
				"‚‚Â‰≥Ú¸ Ï‡ÍÒËÏ‡Î¸ÌÛ Ï≥ÒÚÍ≥ÒÚ¸ ÒÍÎ‡‰Û ‚ ÏÂÚ‡ı ÍÛ·≥˜ÌËı (ÌÂ ÏÂ¯ÌÂ Ì≥Ê 1)"
				"\n-> ";
		} while (!(cin >> storage_max_size) || storage_max_size < 1);
		system("cls");

		CapacityStorage proccess(mdf_width, mdf_length, mdf_height, storage_max_size);
		while (!exit)
		{
			do
			{
				if (!cin.good())
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
				system("cls");
				cout << "Œ¡À≤  Ãƒ‘ Õ¿ — À¿ƒ≤ «¿ –Œ«Ã≤–ŒÃ\n";
				proccess.cout_info();
				cout << "\n\n‚‚Â‰≥Ú¸:"
					"\n1 - ‰Îˇ ÛÔ‡‚Î≥ÌÌˇ ÒÍÎ‡‰ÓÏ"
					"\n2 - ‰Îˇ ‚≥‰Ó·‡ÊÂÌÌˇ ‰ÂÚ‡Î¸ÌÓø ≥ÌÙÓÏ‡ˆ≥ø"
					"\n0 - ‰Îˇ ‚ËıÓ‰Û Á ÔÓ„‡ÏË"
					"\n-> ";
			} while (!(cin >> user_choice) || user_choice < 0 || user_choice > 3);

			switch (user_choice)
			{
			case 1:

				do
				{
					if (!cin.good())
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
					}
					system("cls");
					cout << "Œ¡À≤  Ãƒ‘ Õ¿ — À¿ƒ≤ «¿ –Œ«Ã≤–ŒÃ"
						"\n\n‚‚Â‰≥Ú¸:"
						"\n1 - ‰Îˇ Â∫ÒÚ‡ˆø Ì‡‰ıÓ‰ÊÂÌÌˇ ÌÓ‚Óø Ô‡Ú≥ø Ãƒ‘ Ì‡ ÒÍÎ‡‰"
						"\n2 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÂÂ‰‡˜≥ Ãƒ‘ Á≥ ÒÍÎ‡‰Û Ì‡ ‚ËÓ·ÌËˆÚ‚Ó"
						"\n3 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÓ‚ÂÌÂÌÌˇ Ãƒ‘ Á ‚ËÓ·ÌËˆÚ‚‡ Ì‡ ÒÍÎ‡‰"
						"\n0 - ‰Îˇ ‚≥‰Ï≥ÌË"
						"\n-> ";
				} while (!(cin >> user_choice) || user_choice < 0 || user_choice > 3);

				switch (user_choice)
				{
				case 1:

					do
					{
						if (!cin.good())
						{
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						system("cls");
						cout << "¬¬≈ƒ≤“‹ ¬≤ƒŒÃŒ—“≤ ŸŒƒŒ œ¿–“≤Ø\n\n"
							"‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ ¯ÚÛÍ Ãƒ‘"
							"\n-> ";
					} while (!(cin >> party_amount) || party_amount < 1);
					proccess.new_arrival(console_set_mdf_parameters(), party_amount);
					system("pause");
					break;

				case 2:

					do
					{
						if (!cin.good())
						{
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						system("cls");
						cout << "Œ¡À≤  Ãƒ‘ Õ¿ — À¿ƒ≤ «¿ –Œ«Ã≤–ŒÃ"
							"\n\n‚‚Â‰≥Ú¸:"
							"\n1 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÓÒÚÓø ÔÂÂ‰‡˜≥ ÎËÒÚ≥‚ (Á ‚Â¯ËÌË ÒÚÓÒÛ)"
							"\n2 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÂÂ‰‡˜≥ ÎËÒÚ≥‚ Á ÔÂ‚ÌËÏË ‚Î‡ÒÚË‚ÓÒÚˇÏË (ÔÂÂ·Ë‡˛˜Ë ÒÚÓÒ)"
							"\n0 - ‰Îˇ ‚≥‰Ï≥ÌË"
							"\n-> ";
					} while (!(cin >> user_choice) || user_choice < 0 || user_choice > 2);

					switch (user_choice)
					{

					case 1:
						do
						{
							if (!cin.good())
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
							}
							system("cls");
							cout << "Œ¡À≤  Ãƒ‘ Õ¿ — À¿ƒ≤ «¿ –Œ«Ã≤–ŒÃ"
								"\n\n‚‚Â‰≥Ú¸:"
								"\n1 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÂÂ‰‡˜≥ ‚Ò≥ı ÎËÒÚ≥‚ Á ‚Â¯ËÌË ÒÚÓÒÛ"
								"\n2 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÂÂ‰‡˜≥ Ú≥Î¸ÍË Ó·≥Á‡ÌËı ÎËÒÚ≥‚ Á ‚Â¯ËÌË ÒÚÓÒÛ"
								"\n3 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÂÂ‰‡˜≥ Ú≥Î¸ÍË ˆ≥ÎËı ÎËÒÚ≥‚ Á ‚Â¯ËÌË ÒÚÓÒÛ"
								"\n0 - ‰Îˇ ‚≥‰Ï≥ÌË"
								"\n-> ";
						} while (!(cin >> user_choice) || user_choice < 0 || user_choice > 3);

						switch (user_choice)
						{
						case 1:
							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ œ¿–“≤Ø"
									"\n\n‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ Ãƒ‘"
									"\n-> ";
							} while (!(cin >> party_amount) || party_amount < 1);
							system("cls");
							proccess.put_into_production_top(party_amount);
							system("pause");
							break;

						case 2:
							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ œ¿–“≤Ø"
									"\n\n‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ Ãƒ‘"
									"\n-> ";
							} while (!(cin >> party_amount) || party_amount < 1);
							system("cls");
							proccess.put_into_production_cut(party_amount);
							system("pause");
							break;

						case 3:
							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ œ¿–“≤Ø"
									"\n\n‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ Ãƒ‘"
									"\n-> ";
							} while (!(cin >> party_amount) || party_amount < 1);
							system("cls");
							proccess.put_into_production_whole(party_amount);
							system("pause");
							break;

						default:
							break;
						}
						break;

					case 2:
						do
						{
							if (!cin.good())
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
							}
							system("cls");
							cout << "Œ¡À≤  Ãƒ‘ Õ¿ — À¿ƒ≤ «¿ –Œ«Ã≤–ŒÃ"
								"\n\n‚‚Â‰≥Ú¸:"
								"\n1 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÂÂ‰‡˜≥ ÎËÒÚ≥‚ Á‡ ÓÁÏ≥ÓÏ"
								"\n2 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÂÂ‰‡˜≥ ÎËÒÚ≥‚ Á‡ ˆ≥ÌÓ˛"
								"\n3 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÂÂ‰‡˜≥ ÎËÒÚ≥‚ Á‡ Ì‡Á‚Ó˛"
								"\n4 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÂÂ‰‡˜≥ ÎËÒÚ≥‚ ≥ Á‡ ÓÁÏ≥ÓÏ, ≥ Á‡ ˆ≥ÌÓ˛, ≥ Á‡ Ì‡Á‚Ó˛"
								"\n0 - ‰Îˇ ‚≥‰Ï≥ÌË"
								"\n-> ";
						} while (!(cin >> user_choice) || user_choice < 0 || user_choice > 4);

						switch (user_choice)
						{
						case 1:

							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ Ãƒ‘"
									"\n\n‚‚Â‰≥Ú¸ ¯ËËÌÛ Ãƒ‘ ‚ ÏÏ"
									"\n-> ";
							} while (!(cin >> mdf_width) || mdf_width < 1);

							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ Ãƒ‘"
									"\n\n‚‚Â‰≥Ú¸ ‰Ó‚ÊËÌÛ Ãƒ‘ ‚ ÏÏ"
									"\n-> ";
							} while (!(cin >> mdf_length) || mdf_length < 1);

							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ Ãƒ‘"
									"\n\n‚‚Â‰≥Ú¸ ÚÓ‚˘ËÌÛ Ãƒ‘ ‚ ÏÏ"
									"\n-> ";
							} while (!(cin >> mdf_height) || mdf_height < 1);

							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ œ¿–“≤Ø"
									"\n\n‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ Ãƒ‘"
									"\n-> ";
							} while (!(cin >> party_amount) || party_amount < 1);
							system("cls");
							proccess.put_into_production_special_size(mdf_width, mdf_length, mdf_height, party_amount);
							system("pause");
							break;

						case 2:

							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ Ãƒ‘"
									"\n\n‚‚Â‰≥Ú¸ ˆ≥ÌÛ Ãƒ‘"
									"\n-> ";
							} while (!(cin >> mdf_price) || mdf_price < 0);

							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ œ¿–“≤Ø"
									"\n\n‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ Ãƒ‘"
									"\n-> ";
							} while (!(cin >> party_amount) || party_amount < 1);
							system("cls");
							proccess.put_into_production_special_price(mdf_price, party_amount);
							system("pause");
							break;

						case 3:

							system("cls");
							cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ Ãƒ‘"
								"\n\n‚‚Â‰≥Ú¸ Ì‡Á‚Û Ãƒ‘"
								"\n-> ";
							cin >> mdf_name;

							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ œ¿–“≤Ø"
									"\n\n‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ Ãƒ‘"
									"\n-> ";
							} while (!(cin >> party_amount) || party_amount < 1);
							system("cls");
							proccess.put_into_production_special_name(mdf_name, party_amount);
							system("pause");
							break;

						case 4:

							do
							{
								if (!cin.good())
								{
									cin.clear();
									cin.ignore(INT_MAX, '\n');
								}
								system("cls");
								cout << "¬¬≈ƒ≤“‹ ƒ¿Õ≤ ŸŒƒŒ œ¿–“≤Ø"
									"\n\n‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ Ãƒ‘"
									"\n-> ";
							} while (!(cin >> party_amount) || party_amount < 1);
							system("cls");
							proccess.put_into_production_special(console_set_mdf_parameters(), party_amount);
							system("pause");
							break;

						default:
							break;

						}

						break;

					default:
						break;
					}

					break;

				case 3:

					do
					{
						if (!cin.good())
						{
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						system("cls");
						cout << "Œ¡À≤  Ãƒ‘ Õ¿ — À¿ƒ≤ «¿ –Œ«Ã≤–ŒÃ"
							"\n\n‚‚Â‰≥Ú¸:"
							"\n1 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÓ‚ÂÌÂÌÌˇ Ó·≥ÁÍ≥‚ Á≥ ÒÍÎ‡‰Û"
							"\n2 - ‰Îˇ Â∫ÒÚ‡ˆø ÔÓ‚ÂÌÂÌÌˇ ˆ≥ÎËı ÎËÒÚ≥‚ Á≥ ÒÍÎ‡‰Û"
							"\n0 - ‰Îˇ ‚≥‰Ï≥ÌË"
							"\n-> ";
					} while (!(cin >> user_choice) || user_choice < 0 || user_choice > 2);

					switch (user_choice)
					{

					case 1:
						do
						{
							if (!cin.good())
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
							}
							system("cls");
							cout << "¬¬≈ƒ≤“‹ ¬≤ƒŒÃŒ—“≤ ŸŒƒŒ œŒ¬≈–Õ≈ÕÕﬂ\n\n"
								"‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ ¯ÚÛÍ Ãƒ‘"
								"\n-> ";
						} while (!(cin >> party_amount) || party_amount < 1);

						proccess.return_from_production_cut(console_set_mdf_parameters(), party_amount);
						system("pause");
						break;

					case 2:
						do
						{
							if (!cin.good())
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
							}
							system("cls");
							cout << "¬¬≈ƒ≤“‹ ¬≤ƒŒÃŒ—“≤ ŸŒƒŒ œŒ¬≈–Õ≈ÕÕﬂ\n\n"
								"‚‚Â‰≥Ú¸ Í≥Î¸Í≥ÒÚ¸ ¯ÚÛÍ Ãƒ‘"
								"\n-> ";
						} while (!(cin >> party_amount) || party_amount < 1);

						do
						{
							if (!cin.good())
							{
								cin.clear();
								cin.ignore(INT_MAX, '\n');
							}
							system("cls");
							cout << "¬¬≈ƒ≤“‹ ¬≤ƒŒÃŒ—“≤ ŸŒƒŒ œŒ¬≈–Õ≈ÕÕﬂ\n\n"
								"‚‚Â‰≥Ú¸ ‚≥‰ÒÓÚÓÍ ÁÌËÊÂÌÌˇ ‚‡ÚÓÒÚ≥ Ãƒ‘"
								"\n-> ";
						} while (!(cin >> percentage) || percentage < 0);

						proccess.return_from_production_whole(console_set_mdf_parameters(), party_amount, percentage);
						system("pause");
						break;

					default:
						break;
					}
					break;
				default:
					continue;
				}
				break;

			case 2:

				system("cls");
				cout << "Œ¡À≤  Ãƒ‘ Õ¿ — À¿ƒ≤ «¿ –Œ«Ã≤–ŒÃ\n";
				proccess.cout_detail_info();
				cout << "\n\n";
				system("pause");
				break;

			default:

				do
				{
					if (!cin.good())
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
					}
					system("cls");
					cout << "Œ¡À≤  Ãƒ‘ Õ¿ — À¿ƒ≤ «¿ –Œ«Ã≤–ŒÃ\n\n";
					cout << "‚Ë ‰≥ÈÒÌÓ ıÓ˜ÂÚÂ ‚ËÈÚË Á ÔÓ„‡ÏË?"
						"\n1 - Ì≥"
						"\n0 - Ú‡Í"
						"\n-> ";
				} while (!(cin >> user_choice) || user_choice < 0 || user_choice > 3);

				exit = !user_choice;
				break;
			}
		}

	}

	if (user_choice == 0)
	{ 
		system("cls");
		cout << "‚Ëı≥‰.";
	}

}