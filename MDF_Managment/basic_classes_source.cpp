#include "basic_classes.h"

//������� ��� ��������� ���������� ��� ��� � ������ ������ (��� ���������� ������������)
std::string mdf_info(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, bool is_original_size)
{
	std::string result
	(
		"��'�: " + mdf_name +
		" | ֳ��: " + std::to_string(int(mdf_price)) +
		" | �����: " + std::to_string(mdf_width) + "x" + std::to_string(mdf_length) + "x" + std::to_string(mdf_height) + "��" +
		" | ������: " + (is_original_size ? "����� ���� (�����)" : "������������ ���� (������)")
	);
	return result;
}

std::string mdf_info(const MDF& mdf_object)
{
	std::string result
	(
		"��'�: " + mdf_object.name +
		" | ֳ��: " + std::to_string(int(mdf_object.price)) +
		" | �����: " + std::to_string(mdf_object.width) + "x" + std::to_string(mdf_object.length) + "x" + std::to_string(mdf_object.height) + "��" +
		" | ������: " + (mdf_object.is_original_size ? "����� ���� (�����)" : "������������ ���� (������)")
	);
	return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MDF::MDF(std::string name, double price, int width, int length, int height, bool is_original_size)
{
	this->name = name;
	this->price = price;
	this->width = width;
	this->length = length;
	this->height = height;

	this->is_original_size = is_original_size;
}

std::string MDF::get_name() { return name; }
double MDF::get_price() { return price; }

int MDF::get_width() { return width; }
int MDF::get_length() { return length; }
int MDF::get_height() { return height; }

//������� ������ ���� ��� � �������
bool MDF::is_cut() { return !is_original_size; }

//����� ��� �������� ���
void MDF::cut(int new_width, int new_length, int new_height)
{
	try
	{
		if (width < new_width || length < new_length || height < new_height)
			throw std::string("( ! ������� )| �������� ��� |\n"
				              "             | (i) -> ��� ������ ����� �� ��������.\n\n");

		if (width == new_width && length == new_length && height == new_height)
			throw std::string("( ! ������� )| �������� ��� |\n"
				              "             | (i) -> ��� ������ �� ����������� �� ����������.\n\n");

		width = new_width;
		length = new_length;
		height = new_height;
		is_original_size = false;
		throw std::string("( # )| �������� ��� |\n"
			              "     | (i) -> �������� ������.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

bool MDF::operator == (const MDF& mdf_object)
{
	//���� ��� � ������ � ��'���� ������ ����� �� ����, �� ��������� ����� ������
	if ((mdf_object.name.empty() && mdf_object.price == NULL) || (name.empty() && price == NULL))
		return (mdf_object.width == width && mdf_object.length == length && mdf_object.height == height);

	//���� ��� � ������ � ��'���� ������ ����� �� ������, �� ��������� ����� ����
	if ((mdf_object.name.empty() && mdf_object.width == NULL && mdf_object.length == NULL && mdf_object.height == NULL) || (name.empty() && width == NULL && length == NULL && height == NULL))
		return(mdf_object.price == price);

	//���� ��� � ������ � ��'���� ������ ������ �� ����, �� ��������� ����� �����
	if ((mdf_object.width == NULL && mdf_object.length == NULL && mdf_object.height == NULL && mdf_object.price == NULL) || (width == NULL && length == NULL && height == NULL && price == NULL))
		return(mdf_object.name == name);

	//������ ��������� ���
	return(mdf_object.name == name && mdf_object.price == price && mdf_object.width == width && mdf_object.length == length && mdf_object.height == height);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DefaultStorage::DefaultStorage(int mdf_max_width, int mdf_max_length, int mdf_max_height)
{
	this->mdf_max_width = mdf_max_width;
	this->mdf_max_length = mdf_max_length;
	this->mdf_max_height = mdf_max_height;
}

//��������� ���������� ��� ���, ������� ���� ������� 0
void DefaultStorage::update_storage_mdf_info()
{
	for (auto i = storage_mdf_info.begin(); i != storage_mdf_info.end(); i++)
		if (i->second == 0)
		{
			storage_mdf_info.erase(i);
			update_storage_mdf_info();
			return;
		}
}

//��������� ������� ��� ��� �� �����
size_t DefaultStorage::get_storage_size() { return main_storage.size(); }

//��������� ������� ������
size_t DefaultStorage::get_storage_size_cut()
{
	size_t solution;
	std::stack<MDF> temporary_for_swap;

	while (!main_storage.empty() && main_storage.top().is_cut())
	{
		temporary_for_swap.push(main_storage.top());
		main_storage.pop();
	}

	solution = temporary_for_swap.size();

	while (!temporary_for_swap.empty())
	{
		main_storage.push(temporary_for_swap.top());
		temporary_for_swap.pop();
	}

	return solution;
}

//��������� ������� ����� ������
size_t DefaultStorage::get_storage_size_whole() { return get_storage_size() - get_storage_size_cut(); }

//������ ���� ���� �� �����
void DefaultStorage::new_arrival(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount)
{
	try
	{
		if (party_amount <= 0 || party_amount % 25 != 0)
			throw std::string("( ! ������� )| ���������� ���� ���� �� ����� ��� |\n"
				              "             | (i) -> ������� ���� ��� � ���� �����������.\n\n");

		if (mdf_width > mdf_max_width || mdf_length > mdf_max_length || mdf_height > mdf_max_height)
			throw std::string("( ! ������� )| ���������� ���� ���� �� ����� ��� |\n"
				              "             | (i) -> ����� ��� ���������.\n\n");

		if (mdf_width < 100 || mdf_length < 100)
			throw std::string("( ! ������� )| ���������� ���� ���� �� ����� ��� |\n"
				              "             | (i) -> ����� ��� �������.\n\n");

		//������� ����������
		//��������� ���������� ��� ��� ���
		std::string current_mdf_info = mdf_info(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height);

		//�������� ����� ���������� ���
		std::map<std::string, int>::iterator it = storage_mdf_info.find(current_mdf_info);

		//���� ��� ��� �
		if (it != storage_mdf_info.end())
		{
			//�������� �� ������� �� ���������
			it->second += party_amount;
		}
		//������
		else
		{
			//������ ���������� ��� ��� ���
			storage_mdf_info.emplace(current_mdf_info, party_amount);
		}

		//������� ������� ���� ����
		//���� ������ � ������
		if (!main_storage.empty() && main_storage.top().is_cut())
		{
			//���������� ���� ��� ������
			std::stack<MDF> temporary_for_swap;

			//������� ������
			while (main_storage.top().is_cut())
			{
				temporary_for_swap.push(main_storage.top());
				main_storage.pop();
			}

			//�������� ��� ���
			for (int i = 0; i < party_amount; i++)
				main_storage.push(MDF(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height));

			//��������� ������ �� ����
			while (!temporary_for_swap.empty())
			{
				main_storage.push(temporary_for_swap.top());
				temporary_for_swap.pop();
			}
		}

		else
		{
			for (int i = 0; i < party_amount; i++)
				main_storage.push(MDF(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height));
		}

		throw std::string("( # )| ���������� ���� ���� �� ����� ��� |\n"
			              "     | (i) -> �������� ������.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

//������ ���� ���� �� ����� � ���������� � ��'����� ���
void DefaultStorage::new_arrival(const MDF& mdf_object, int party_amount)
{
	this->new_arrival(mdf_object.name, mdf_object.price, mdf_object.width, mdf_object.length, mdf_object.height, party_amount);
}

//�������� �� �����������, ������ ����� ������
void DefaultStorage::put_into_production_top(int party_amount)
{
	try
	{
		if (main_storage.size() < party_amount)
			throw std::string("( ! ������� )| �������� �� ����������� ��� |\n"
				              "             | (i) -> �� ����� �� ������� ���, ��� �������� �������� �� ��������� �������.\n\n");

		for (int i = 0; i < party_amount; i++)
		{
			//�������� ���������� ��� ��� ���
			std::string current_mdf_info = mdf_info(main_storage.top());
			storage_mdf_info.find(current_mdf_info)->second--;

			//�������� ��� � ������
			main_storage.pop();
		}

		//��������� ����������
		update_storage_mdf_info();

		throw std::string("( # )| �������� �� ����������� ��� |\n"
			              "     | (i) -> �������� ������.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

//�������� �� �����������, ������ ����� ������ ����� ������
void DefaultStorage::put_into_production_cut(int party_amount)
{
	try
	{
		if (get_storage_size_cut() < party_amount)
			throw std::string("( ! ������� )| �������� �� ����������� ������ ��� |\n"
				              "             | (i) -> �� ����� �� ������� ������ ���, ��� �������� �������� �� ��������� �������.\n\n");

		for (int i = 0; i < party_amount; i++)
		{
			std::string current_mdf_info = mdf_info(main_storage.top());
			storage_mdf_info.find(current_mdf_info)->second--;

			main_storage.pop();
		}

		update_storage_mdf_info();

		throw std::string("( # )| �������� �� ����������� ������ ��� |\n"
			              "     | (i) -> �������� ������.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

//�������� �� �����������, ������ ����� ��� ����� ������
void DefaultStorage::put_into_production_whole(int party_amount)
{
	try
	{
		if (get_storage_size_whole() < party_amount)
			throw std::string("( ! ������� )| �������� �� ����������� ����� ��� |\n"
				              "             | (i) -> �� ����� �� ������� ����� ���, ��� �������� �������� �� ��������� �������.\n\n");

		//���� ������ � ������
		if (main_storage.top().is_cut())
		{
			//���������� ���� ��� ������
			std::stack<MDF> temporary_for_swap;

			//������� ������
			while (main_storage.top().is_cut())
			{
				temporary_for_swap.push(main_storage.top());
				main_storage.pop();
			}

			//�������� � ������ ��� �����
			for (int i = 0; i < party_amount; i++)
			{
				std::string current_mdf_info = mdf_info(main_storage.top());
				storage_mdf_info.find(current_mdf_info)->second--;

				main_storage.pop();
			}

			update_storage_mdf_info();

			//��������� ������
			while (!temporary_for_swap.empty())
			{
				main_storage.push(temporary_for_swap.top());
				temporary_for_swap.pop();
			}
		}

		else
		{
			for (int i = 0; i < party_amount; i++)
			{
				std::string current_mdf_info = mdf_info(main_storage.top());
				storage_mdf_info.find(current_mdf_info)->second--;

				main_storage.pop();
			}

			update_storage_mdf_info();
		}

		throw std::string("( # )| �������� �� ����������� ����� ��� |\n"
			              "     | (i) -> �������� ������.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

//�������� �� �����������, ����������� ����� ������ ����� �� �������������
void DefaultStorage::put_into_production_special(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount)
{
	try
	{
		//�������� ����� ��� ���������� �� �������� �����
		std::stack<MDF> not_needed_elements, needed_elements;

		//���������� �� �����
		while (!main_storage.empty())
		{
			//���� �������� �������� ���� �� �������������
			if (main_storage.top() == MDF(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height))
				needed_elements.push(main_storage.top());

			//���� �
			else
				not_needed_elements.push(main_storage.top());

			main_storage.pop();
		}

		if (needed_elements.size() < party_amount)
			throw std::string("( ! ������� )| �������� �� ����������� ������ ��� |\n"
				              "             | (i) -> �� ����� �� ������� ��� � ������ �������������, ��� �������� �������� �� ��������� �������.\n\n");

		//�������� � ������ ������ �����
		for (int i = 0; i < party_amount; i++)
		{
			std::string current_mdf_info = mdf_info(needed_elements.top());
			storage_mdf_info.find(current_mdf_info)->second--;

			needed_elements.pop();
		}

		update_storage_mdf_info();

		//��������� ������� �� �������� ����� �� �����, ������������ ��������� ���������
		//��������� �������� �� ��� �����
		while (!needed_elements.empty() && !needed_elements.top().is_cut())
		{
			main_storage.push(needed_elements.top());
			needed_elements.pop();
		}

		while (!not_needed_elements.empty() && !not_needed_elements.top().is_cut())
		{
			main_storage.push(not_needed_elements.top());
			not_needed_elements.pop();
		}

		//������ ������� �� ������� ������ ������
		while (!needed_elements.empty())
		{
			main_storage.push(needed_elements.top());
			needed_elements.pop();
		}

		while (!not_needed_elements.empty())
		{
			main_storage.push(not_needed_elements.top());
			not_needed_elements.pop();
		}

		throw std::string("( # )| �������� �� ����������� ������ ��� |\n"
			              "     | (i) -> �������� ������.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

//�������� �� �����������, ����������� ����� ������ ����� �� ������������� � ���������� � ��'����� ���
void DefaultStorage::put_into_production_special(const MDF& mdf_object, int party_amount)
{
	this->put_into_production_special(mdf_object.name, mdf_object.price, mdf_object.width, mdf_object.length, mdf_object.height, party_amount);
}

//�������� �� �����������, ����������� ����� ������ ����� �� �������
void DefaultStorage::put_into_production_special_size(int mdf_width, int mdf_length, int mdf_height, int party_amount)
{
	this->put_into_production_special("", NULL, mdf_width, mdf_length, mdf_height, party_amount);
}

//�������� �� �����������, ����������� ����� ������ ����� �� ������
void DefaultStorage::put_into_production_special_name(std::string mdf_name, int party_amount)
{
	this->put_into_production_special(mdf_name, NULL, NULL, NULL, NULL, party_amount);
}

//�������� �� �����������, ����������� ����� ������ ����� �� �����
void DefaultStorage::put_into_production_special_price(double mdf_price, int party_amount)
{
	this->put_into_production_special("", mdf_price, NULL, NULL, NULL, party_amount);
}

//���������� � ����������� ������
void DefaultStorage::return_from_production_cut(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount)
{
	try
	{
		if (mdf_width >= mdf_max_width || mdf_length >= mdf_max_length || mdf_height >= mdf_max_height)
			throw std::string("( ! ������� )| ���������� � ����������� ������ ��� |\n"
				              "             | (i) -> ����� ��� ���������.\n\n");

		if (mdf_width < 100 || mdf_length < 100)
			throw std::string("( ! ������� )| ���������� � ����������� ������ ��� |\n"
			               	  "             | (i) -> ����� ��� �������.\n\n");

		std::string current_mdf_info = mdf_info(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height, false);
		std::map<std::string, int>::iterator it = storage_mdf_info.find(current_mdf_info);

		if (it != storage_mdf_info.end())
			it->second += party_amount;

		else
			storage_mdf_info.emplace(current_mdf_info, party_amount);
		
		for (int i = 0; i < party_amount; i++)
			main_storage.push(MDF(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height, false));

		throw std::string("( # )| ���������� � ����������� ������ ��� |\n"
			              "     | (i) -> �������� ������.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

//���������� � ����������� ������ � ���������� � ��'����� ���
void DefaultStorage::return_from_production_cut(const MDF& mdf_object, int party_amount)
{
	this->return_from_production_cut(mdf_object.name, mdf_object.price, mdf_object.width, mdf_object.length, mdf_object.height, party_amount);
}

//���������� � ����������� ����� �����
void DefaultStorage::return_from_production_whole(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount, double percents)
{
	try
	{
		if (mdf_width > mdf_max_width || mdf_length > mdf_max_length || mdf_height > mdf_max_height)
			throw std::string("( ! ������� )| ���������� � ����������� ����� ��� |\n"
				              "             | (i) -> ����� ��� ���������.\n\n");

		if (mdf_width < 100 || mdf_length < 100)
			throw std::string("( ! ������� )| ���������� � ����������� ����� ��� |\n"
				              "             | (i) -> ����� ��� �������.\n\n");

		mdf_price -= mdf_price / 100 * percents;

		std::string current_mdf_info = mdf_info(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height);
		std::map<std::string, int>::iterator it = storage_mdf_info.find(current_mdf_info);

		if (it != storage_mdf_info.end())
			it->second += party_amount;

		else
			storage_mdf_info.emplace(current_mdf_info, party_amount);
		

		if (!main_storage.empty() && main_storage.top().is_cut())
		{
			std::stack<MDF> temporary_for_swap;

			while (main_storage.top().is_cut())
			{
				temporary_for_swap.push(main_storage.top());
				main_storage.pop();
			}

			for (int i = 0; i < party_amount; i++)
				main_storage.push(MDF(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height));

			while (!temporary_for_swap.empty())
			{
				main_storage.push(temporary_for_swap.top());
				temporary_for_swap.pop();
			}
		}

		else
		{
			for (int i = 0; i < party_amount; i++)
				main_storage.push(MDF(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height));

		}

		throw std::string("( # )| ���������� � ����������� ����� ��� |\n"
			              "     | (i) -> �������� ������.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

//���������� � ����������� ����� ����� � ���������� � ��'����� ���
void DefaultStorage::return_from_production_whole(const MDF& mdf_object, int party_amount, double percents)
{
	this->return_from_production_whole(mdf_object.name, mdf_object.price, mdf_object.width, mdf_object.length, mdf_object.height, party_amount, percents);
}

void DefaultStorage::cout_info()
{
	std::cout << "    �������ֲ� ��� �����\n"
		         "| ������� ���      | -> " << get_storage_size() << "\n"
		         "| ������� ������ | -> " << get_storage_size_cut() << "\n"
		         "| ������� �����    | -> " << get_storage_size_whole() << "\n";
}

void DefaultStorage::cout_detail_info()
{
	std::cout << "�������� ����������:\n\n";

	if (main_storage.size() == 0)
		std::cout << "����� ������.";

	else
	{
		int id = 0;
		for (auto i = storage_mdf_info.begin(); i != storage_mdf_info.end(); i++)
			std::cout << ++id << " | " << i->first << " -> " << i->second << " ����;\n";
	}
}