#include "extedned_classes.h"
using namespace std;

void console_set_max_size_parameters(int& width, int& length, int& height, int width_length_minimal_parameter = 100, int height_minimal_parameter = 1)
{
	system("cls");
	cout << "������������ ��������\n!��� ������ ���� ���������\n!������������ ����� ���� �������� �����\n\n";
	system("pause");

	do 
	{
		//���� ������� ������������ ��� �����
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		system("cls");
		cout << "������������ ��������\n!��� ������ ���� ���������\n!������������ ����� ���� �������� �����\n\n"
			"������ ����������� ������� ������ ��� � �� (�� ����� �� " << width_length_minimal_parameter << ")"
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
		cout << "������������ ��������\n!��� ������ ���� ���������\n!������������ ����� ���� �������� �����\n\n"
			"������ ����������� ������� ������� ��� � �� (�� ����� �� " << width_length_minimal_parameter << ")"
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
		cout << "������������ ��������\n!��� ������ ���� ���������\n!������������ ����� ���� �������� �����\n\n"
			"������ ����������� ������� ������� ��� � �� (�� ����� �� " << height_minimal_parameter << ")"
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
	cout << "���Ĳ�� ²�����Ҳ ���� ���\n\n"
		"������ ����� ���"
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
		cout << "���Ĳ�� ²�����Ҳ ���� ���\n\n"
			"������ ������� ���"
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
		cout << "���Ĳ�� ²�����Ҳ ���� ���\n\n"
			"������ ������ ��� � ��"
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
		cout << "���Ĳ�� ²�����Ҳ ���� ���\n\n"
			"������ ������� ��� � ��"
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
		cout << "���Ĳ�� ²�����Ҳ ���� ���\n\n"
			"������ ������� ��� � ��"
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
		//���� ������� ������������ ��� �����
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		system("cls");
		cout << "�������� ��� ��˲�� ��� �� ����Ĳ"
			"\n\n������:"
			"\n1 - ��� ����� �� ������� ���"
			"\n2 - ��� ����� �� ������� ���"
			"\n0 - ��� ������ � ��������"
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
				cout << "��˲� ��� �� ����Ĳ �� ���Ҳ���\n";
				proccess.cout_info();
				cout << "\n\n������:"
					"\n1 - ��� ��������� �������"
					"\n2 - ��� ����������� �������� ����������"
					"\n0 - ��� ������ � ��������"
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
					cout << "��˲� ��� �� ����Ĳ �� ���Ҳ���"
						"\n\n������:"
						"\n1 - ��� �������� ����������� ���� ���� ��� �� �����"
						"\n2 - ��� �������� �������� ��� � ������ �� �����������"
						"\n3 - ��� �������� ���������� ��� � ����������� �� �����"
						"\n0 - ��� �����"
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
						cout << "���Ĳ�� ²�����Ҳ ���� ���Ҳ�\n\n"
							"������ ������� ���� ���"
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
						cout << "��˲� ��� �� ����Ĳ �� ���Ҳ���"
							"\n\n������:"
							"\n1 - ��� �������� ������ �������� ����� (� ������� �����)"
							"\n2 - ��� �������� �������� ����� � ������� ������������� (����������� ����)"
							"\n0 - ��� �����"
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
							cout << "��˲� ��� �� ����Ĳ �� ���Ҳ���"
								"\n\n������:"
								"\n1 - ��� �������� �������� ��� ����� � ������� �����"
								"\n2 - ��� �������� �������� ����� �������� ����� � ������� �����"
								"\n3 - ��� �������� �������� ����� ����� ����� � ������� �����"
								"\n0 - ��� �����"
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
								cout << "���Ĳ�� ��Ͳ ���� ���Ҳ�"
									"\n\n������ ������� ���"
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
								cout << "���Ĳ�� ��Ͳ ���� ���Ҳ�"
									"\n\n������ ������� ���"
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
								cout << "���Ĳ�� ��Ͳ ���� ���Ҳ�"
									"\n\n������ ������� ���"
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
							cout << "��˲� ��� �� ����Ĳ �� ���Ҳ���"
								"\n\n������:"
								"\n1 - ��� �������� �������� ����� �� �������"
								"\n2 - ��� �������� �������� ����� �� �����"
								"\n3 - ��� �������� �������� ����� �� ������"
								"\n4 - ��� �������� �������� ����� � �� �������, � �� �����, � �� ������"
								"\n0 - ��� �����"
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
								cout << "���Ĳ�� ��Ͳ ���� ���"
									"\n\n������ ������ ��� � ��"
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
								cout << "���Ĳ�� ��Ͳ ���� ���"
									"\n\n������ ������� ��� � ��"
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
								cout << "���Ĳ�� ��Ͳ ���� ���"
									"\n\n������ ������� ��� � ��"
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
								cout << "���Ĳ�� ��Ͳ ���� ���Ҳ�"
									"\n\n������ ������� ���"
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
								cout << "���Ĳ�� ��Ͳ ���� ���"
									"\n\n������ ���� ���"
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
								cout << "���Ĳ�� ��Ͳ ���� ���Ҳ�"
									"\n\n������ ������� ���"
									"\n-> ";
							} while (!(cin >> party_amount) || party_amount < 1);
							system("cls");
							proccess.put_into_production_special_price(mdf_price, party_amount);
							system("pause");
							break;

						case 3:

							system("cls");
							cout << "���Ĳ�� ��Ͳ ���� ���"
								"\n\n������ ����� ���"
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
								cout << "���Ĳ�� ��Ͳ ���� ���Ҳ�"
									"\n\n������ ������� ���"
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
								cout << "���Ĳ�� ��Ͳ ���� ���Ҳ�"
									"\n\n������ ������� ���"
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
						cout << "��˲� ��� �� ����Ĳ �� ���Ҳ���"
							"\n\n������:"
							"\n1 - ��� �������� ���������� ������ � ������"
							"\n2 - ��� �������� ���������� ����� ����� � ������"
							"\n0 - ��� �����"
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
							cout << "���Ĳ�� ²�����Ҳ ���� ����������\n\n"
								"������ ������� ���� ���"
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
							cout << "���Ĳ�� ²�����Ҳ ���� ����������\n\n"
								"������ ������� ���� ���"
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
							cout << "���Ĳ�� ²�����Ҳ ���� ����������\n\n"
								"������ ������� �������� ������� ���"
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
				cout << "��˲� ��� �� ����Ĳ �� ���Ҳ���\n";
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
					cout << "��˲� ��� �� ����Ĳ �� ���Ҳ���\n\n";
					cout << "�� ����� ������ ����� � ��������?"
						"\n1 - �"
						"\n0 - ���"
						"\n-> ";
				} while (!(cin >> user_choice) || user_choice < 0 || user_choice > 3);

				exit = !user_choice;
				break;
			}
		}

	}

	//��� ����� ����������, ������� ���������� ����
	if (user_choice == 2)
	{

		console_set_max_size_parameters(mdf_width, mdf_length, mdf_height);
		//��������� �������� ����������� ������� ������
		do
		{
			if (!cin.good())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			system("cls");
			cout << "������������ ��������\n!��� ������ ���� ���������\n!������������ ����� ���� �������� �����\n\n"
				"������ ����������� ������� ������ � ������ ������� (�� ����� �� 1)"
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
				cout << "��˲� ��� �� ����Ĳ �� ���̲���\n";
				proccess.cout_info();
				cout << "\n\n������:"
					"\n1 - ��� ��������� �������"
					"\n2 - ��� ����������� �������� ����������"
					"\n0 - ��� ������ � ��������"
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
					cout << "��˲� ��� �� ����Ĳ �� ���̲���"
						"\n\n������:"
						"\n1 - ��� �������� ����������� ���� ���� ��� �� �����"
						"\n2 - ��� �������� �������� ��� � ������ �� �����������"
						"\n3 - ��� �������� ���������� ��� � ����������� �� �����"
						"\n0 - ��� �����"
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
						cout << "���Ĳ�� ²�����Ҳ ���� ���Ҳ�\n\n"
							"������ ������� ���� ���"
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
						cout << "��˲� ��� �� ����Ĳ �� ���̲���"
							"\n\n������:"
							"\n1 - ��� �������� ������ �������� ����� (� ������� �����)"
							"\n2 - ��� �������� �������� ����� � ������� ������������� (����������� ����)"
							"\n0 - ��� �����"
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
							cout << "��˲� ��� �� ����Ĳ �� ���̲���"
								"\n\n������:"
								"\n1 - ��� �������� �������� ��� ����� � ������� �����"
								"\n2 - ��� �������� �������� ����� �������� ����� � ������� �����"
								"\n3 - ��� �������� �������� ����� ����� ����� � ������� �����"
								"\n0 - ��� �����"
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
								cout << "���Ĳ�� ��Ͳ ���� ���Ҳ�"
									"\n\n������ ������� ���"
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
								cout << "���Ĳ�� ��Ͳ ���� ���Ҳ�"
									"\n\n������ ������� ���"
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
								cout << "���Ĳ�� ��Ͳ ���� ���Ҳ�"
									"\n\n������ ������� ���"
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
							cout << "��˲� ��� �� ����Ĳ �� ���̲���"
								"\n\n������:"
								"\n1 - ��� �������� �������� ����� �� �������"
								"\n2 - ��� �������� �������� ����� �� �����"
								"\n3 - ��� �������� �������� ����� �� ������"
								"\n4 - ��� �������� �������� ����� � �� �������, � �� �����, � �� ������"
								"\n0 - ��� �����"
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
								cout << "���Ĳ�� ��Ͳ ���� ���"
									"\n\n������ ������ ��� � ��"
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
								cout << "���Ĳ�� ��Ͳ ���� ���"
									"\n\n������ ������� ��� � ��"
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
								cout << "���Ĳ�� ��Ͳ ���� ���"
									"\n\n������ ������� ��� � ��"
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
								cout << "���Ĳ�� ��Ͳ ���� ���Ҳ�"
									"\n\n������ ������� ���"
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
								cout << "���Ĳ�� ��Ͳ ���� ���"
									"\n\n������ ���� ���"
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
								cout << "���Ĳ�� ��Ͳ ���� ���Ҳ�"
									"\n\n������ ������� ���"
									"\n-> ";
							} while (!(cin >> party_amount) || party_amount < 1);
							system("cls");
							proccess.put_into_production_special_price(mdf_price, party_amount);
							system("pause");
							break;

						case 3:

							system("cls");
							cout << "���Ĳ�� ��Ͳ ���� ���"
								"\n\n������ ����� ���"
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
								cout << "���Ĳ�� ��Ͳ ���� ���Ҳ�"
									"\n\n������ ������� ���"
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
								cout << "���Ĳ�� ��Ͳ ���� ���Ҳ�"
									"\n\n������ ������� ���"
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
						cout << "��˲� ��� �� ����Ĳ �� ���̲���"
							"\n\n������:"
							"\n1 - ��� �������� ���������� ������ � ������"
							"\n2 - ��� �������� ���������� ����� ����� � ������"
							"\n0 - ��� �����"
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
							cout << "���Ĳ�� ²�����Ҳ ���� ����������\n\n"
								"������ ������� ���� ���"
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
							cout << "���Ĳ�� ²�����Ҳ ���� ����������\n\n"
								"������ ������� ���� ���"
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
							cout << "���Ĳ�� ²�����Ҳ ���� ����������\n\n"
								"������ ������� �������� ������� ���"
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
				cout << "��˲� ��� �� ����Ĳ �� ���̲���\n";
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
					cout << "��˲� ��� �� ����Ĳ �� ���̲���\n\n";
					cout << "�� ����� ������ ����� � ��������?"
						"\n1 - �"
						"\n0 - ���"
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
		cout << "�����.";
	}

}