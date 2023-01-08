#include "basic_classes.h"

//функції для створення інформації про МДФ у вигляді тексту (для подальшого використання)
std::string mdf_info(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, bool is_original_size)
{
	std::string result
	(
		"Ім'я: " + mdf_name +
		" | Ціна: " + std::to_string(int(mdf_price)) +
		" | Розмір: " + std::to_string(mdf_width) + "x" + std::to_string(mdf_length) + "x" + std::to_string(mdf_height) + "мм" +
		" | Статус: " + (is_original_size ? "новий лист (цілий)" : "використаний лист (обрізок)")
	);
	return result;
}

std::string mdf_info(const MDF& mdf_object)
{
	std::string result
	(
		"Ім'я: " + mdf_object.name +
		" | Ціна: " + std::to_string(int(mdf_object.price)) +
		" | Розмір: " + std::to_string(mdf_object.width) + "x" + std::to_string(mdf_object.length) + "x" + std::to_string(mdf_object.height) + "мм" +
		" | Статус: " + (mdf_object.is_original_size ? "новий лист (цілий)" : "використаний лист (обрізок)")
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

//повертає істину якщо МДФ є обрізком
bool MDF::is_cut() { return !is_original_size; }

//метод для обрізання МДФ
void MDF::cut(int new_width, int new_length, int new_height)
{
	try
	{
		if (width < new_width || length < new_length || height < new_height)
			throw std::string("( ! помилка )| обрізання МДФ |\n"
				              "             | (i) -> нові розміри більші за початкові.\n\n");

		if (width == new_width && length == new_length && height == new_height)
			throw std::string("( ! помилка )| обрізання МДФ |\n"
				              "             | (i) -> нові розміри не відрізняються від початкових.\n\n");

		width = new_width;
		length = new_length;
		height = new_height;
		is_original_size = false;
		throw std::string("( # )| обрізання МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

bool MDF::operator == (const MDF& mdf_object)
{
	//якщо хоч в одному з об'єктів відсутні назва та ціна, то порівнюємо тільки розміри
	if ((mdf_object.name.empty() && mdf_object.price == NULL) || (name.empty() && price == NULL))
		return (mdf_object.width == width && mdf_object.length == length && mdf_object.height == height);

	//якщо хоч в одному з об'єктів відсутні назва та розміри, то порівнюємо тільки ціну
	if ((mdf_object.name.empty() && mdf_object.width == NULL && mdf_object.length == NULL && mdf_object.height == NULL) || (name.empty() && width == NULL && length == NULL && height == NULL))
		return(mdf_object.price == price);

	//якщо хоч в одному з об'єктів відсутні розміри та ціна, то порівнюємо тільки назву
	if ((mdf_object.width == NULL && mdf_object.length == NULL && mdf_object.height == NULL && mdf_object.price == NULL) || (width == NULL && length == NULL && height == NULL && price == NULL))
		return(mdf_object.name == name);

	//інакше порівнюємо все
	return(mdf_object.name == name && mdf_object.price == price && mdf_object.width == width && mdf_object.length == length && mdf_object.height == height);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DefaultStorage::DefaultStorage(int mdf_max_width, int mdf_max_length, int mdf_max_height)
{
	this->mdf_max_width = mdf_max_width;
	this->mdf_max_length = mdf_max_length;
	this->mdf_max_height = mdf_max_height;
}

//вилучення інформації про МДФ, кількість яких дорівнює 0
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

//повернути кількість всіх МДФ на складі
size_t DefaultStorage::get_storage_size() { return main_storage.size(); }

//повернути кількість обрізків
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

//повернути кількість цілих частин
size_t DefaultStorage::get_storage_size_whole() { return get_storage_size() - get_storage_size_cut(); }

//прихід нової партії на склад
void DefaultStorage::new_arrival(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount)
{
	try
	{
		if (party_amount <= 0 || party_amount % 25 != 0)
			throw std::string("( ! помилка )| постачання нової партії на склад МДФ |\n"
				              "             | (i) -> кількість штук МДФ в партії незадовільна.\n\n");

		if (mdf_width > mdf_max_width || mdf_length > mdf_max_length || mdf_height > mdf_max_height)
			throw std::string("( ! помилка )| постачання нової партії на склад МДФ |\n"
				              "             | (i) -> розмір МДФ завеликий.\n\n");

		if (mdf_width < 100 || mdf_length < 100)
			throw std::string("( ! помилка )| постачання нової партії на склад МДФ |\n"
				              "             | (i) -> розмір МДФ замалий.\n\n");

		//обробка інформації
		//створення інформації про дані МДФ
		std::string current_mdf_info = mdf_info(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height);

		//виконуємо пошук ідентичних МДФ
		std::map<std::string, int>::iterator it = storage_mdf_info.find(current_mdf_info);

		//якщо такі вже є
		if (it != storage_mdf_info.end())
		{
			//збільшуємо їх кількість на визначену
			it->second += party_amount;
		}
		//інакше
		else
		{
			//додаємо інформацію про нові МДФ
			storage_mdf_info.emplace(current_mdf_info, party_amount);
		}

		//обробка приходу нової партії
		//якщо зверху є обрізки
		if (!main_storage.empty() && main_storage.top().is_cut())
		{
			//тимчасовий стек для обрізків
			std::stack<MDF> temporary_for_swap;

			//виймаємо обрізки
			while (main_storage.top().is_cut())
			{
				temporary_for_swap.push(main_storage.top());
				main_storage.pop();
			}

			//складаємо нові МДФ
			for (int i = 0; i < party_amount; i++)
				main_storage.push(MDF(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height));

			//повертаємо обрізки на місце
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

		throw std::string("( # )| постачання нової партії на склад МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

//прихід нової партії на склад в параметрах з об'єктом МДФ
void DefaultStorage::new_arrival(const MDF& mdf_object, int party_amount)
{
	this->new_arrival(mdf_object.name, mdf_object.price, mdf_object.width, mdf_object.length, mdf_object.height, party_amount);
}

//передача на виробництво, беручи листи зверху
void DefaultStorage::put_into_production_top(int party_amount)
{
	try
	{
		if (main_storage.size() < party_amount)
			throw std::string("( ! помилка )| передача на виробництво МДФ |\n"
				              "             | (i) -> на складі не вистачає МДФ, щоб виконати передачу на визначену кількість.\n\n");

		for (int i = 0; i < party_amount; i++)
		{
			//вилучаємо інформацію про дані МДФ
			std::string current_mdf_info = mdf_info(main_storage.top());
			storage_mdf_info.find(current_mdf_info)->second--;

			//вилучаємо МДФ зі складу
			main_storage.pop();
		}

		//оновлюємо інформацію
		update_storage_mdf_info();

		throw std::string("( # )| передача на виробництво МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

//передача на виробництво, беручи тільки обрізані листи зверху
void DefaultStorage::put_into_production_cut(int party_amount)
{
	try
	{
		if (get_storage_size_cut() < party_amount)
			throw std::string("( ! помилка )| передача на виробництво обрізків МДФ |\n"
				              "             | (i) -> на складі не вистачає обрізків МДФ, щоб виконати передачу на визначену кількість.\n\n");

		for (int i = 0; i < party_amount; i++)
		{
			std::string current_mdf_info = mdf_info(main_storage.top());
			storage_mdf_info.find(current_mdf_info)->second--;

			main_storage.pop();
		}

		update_storage_mdf_info();

		throw std::string("( # )| передача на виробництво обрізків МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

//передача на виробництво, беручи тільки цілі листи зверху
void DefaultStorage::put_into_production_whole(int party_amount)
{
	try
	{
		if (get_storage_size_whole() < party_amount)
			throw std::string("( ! помилка )| передача на виробництво цілих МДФ |\n"
				              "             | (i) -> на складі не вистачає цілих МДФ, щоб виконати передачу на визначену кількість.\n\n");

		//якщо зверху є обрізки
		if (main_storage.top().is_cut())
		{
			//тимчасовий стек для обрізків
			std::stack<MDF> temporary_for_swap;

			//виймаємо обрізки
			while (main_storage.top().is_cut())
			{
				temporary_for_swap.push(main_storage.top());
				main_storage.pop();
			}

			//вилучаємо зі складу цілі листи
			for (int i = 0; i < party_amount; i++)
			{
				std::string current_mdf_info = mdf_info(main_storage.top());
				storage_mdf_info.find(current_mdf_info)->second--;

				main_storage.pop();
			}

			update_storage_mdf_info();

			//повертаємо обрізки
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

		throw std::string("( # )| передача на виробництво цілих МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

//передача на виробництво, перебираючи тільки потрібні листи за властивостями
void DefaultStorage::put_into_production_special(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount)
{
	try
	{
		//тимчасові стеки для непотрібних та потрібних листів
		std::stack<MDF> not_needed_elements, needed_elements;

		//перебираємо усі листи
		while (!main_storage.empty())
		{
			//якщо знайдено потрібний лист за властивостями
			if (main_storage.top() == MDF(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height))
				needed_elements.push(main_storage.top());

			//якщо ні
			else
				not_needed_elements.push(main_storage.top());

			main_storage.pop();
		}

		if (needed_elements.size() < party_amount)
			throw std::string("( ! помилка )| передача на виробництво певних МДФ |\n"
				              "             | (i) -> на складі не вистачає МДФ з даними властивостями, щоб виконати передачу на визначену кількість.\n\n");

		//вилучаємо зі складу потрібні листи
		for (int i = 0; i < party_amount; i++)
		{
			std::string current_mdf_info = mdf_info(needed_elements.top());
			storage_mdf_info.find(current_mdf_info)->second--;

			needed_elements.pop();
		}

		update_storage_mdf_info();

		//повертаємо залишки та непотрібні листи на склад, дотримуючись правильної структури
		//повертаємо спочатку всі цілі листи
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

		//згодом кладемо всі залишені обрізки нагору
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

		throw std::string("( # )| передача на виробництво певних МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

//передача на виробництво, перебираючи тільки потрібні листи за властивостями в параметрах з об'єктом МДФ
void DefaultStorage::put_into_production_special(const MDF& mdf_object, int party_amount)
{
	this->put_into_production_special(mdf_object.name, mdf_object.price, mdf_object.width, mdf_object.length, mdf_object.height, party_amount);
}

//передача на виробництво, перебираючи тільки потрібні листи за розміром
void DefaultStorage::put_into_production_special_size(int mdf_width, int mdf_length, int mdf_height, int party_amount)
{
	this->put_into_production_special("", NULL, mdf_width, mdf_length, mdf_height, party_amount);
}

//передача на виробництво, перебираючи тільки потрібні листи за назвою
void DefaultStorage::put_into_production_special_name(std::string mdf_name, int party_amount)
{
	this->put_into_production_special(mdf_name, NULL, NULL, NULL, NULL, party_amount);
}

//передача на виробництво, перебираючи тільки потрібні листи за ціною
void DefaultStorage::put_into_production_special_price(double mdf_price, int party_amount)
{
	this->put_into_production_special("", mdf_price, NULL, NULL, NULL, party_amount);
}

//повернення з виробництва обрізків
void DefaultStorage::return_from_production_cut(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount)
{
	try
	{
		if (mdf_width >= mdf_max_width || mdf_length >= mdf_max_length || mdf_height >= mdf_max_height)
			throw std::string("( ! помилка )| повернення з виробництва обрізків МДФ |\n"
				              "             | (i) -> розмір МДФ завеликий.\n\n");

		if (mdf_width < 100 || mdf_length < 100)
			throw std::string("( ! помилка )| повернення з виробництва обрізків МДФ |\n"
			               	  "             | (i) -> розмір МДФ замалий.\n\n");

		std::string current_mdf_info = mdf_info(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height, false);
		std::map<std::string, int>::iterator it = storage_mdf_info.find(current_mdf_info);

		if (it != storage_mdf_info.end())
			it->second += party_amount;

		else
			storage_mdf_info.emplace(current_mdf_info, party_amount);
		
		for (int i = 0; i < party_amount; i++)
			main_storage.push(MDF(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height, false));

		throw std::string("( # )| повернення з виробництва обрізків МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

//повернення з виробництва обрізків в параметрах з об'єктом МДФ
void DefaultStorage::return_from_production_cut(const MDF& mdf_object, int party_amount)
{
	this->return_from_production_cut(mdf_object.name, mdf_object.price, mdf_object.width, mdf_object.length, mdf_object.height, party_amount);
}

//повернення з виробництва цілих листів
void DefaultStorage::return_from_production_whole(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount, double percents)
{
	try
	{
		if (mdf_width > mdf_max_width || mdf_length > mdf_max_length || mdf_height > mdf_max_height)
			throw std::string("( ! помилка )| повернення з виробництва цілих МДФ |\n"
				              "             | (i) -> розмір МДФ завеликий.\n\n");

		if (mdf_width < 100 || mdf_length < 100)
			throw std::string("( ! помилка )| повернення з виробництва цілих МДФ |\n"
				              "             | (i) -> розмір МДФ замалий.\n\n");

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

		throw std::string("( # )| повернення з виробництва цілих МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

//повернення з виробництва цілих листів в параметрах з об'єктом МДФ
void DefaultStorage::return_from_production_whole(const MDF& mdf_object, int party_amount, double percents)
{
	this->return_from_production_whole(mdf_object.name, mdf_object.price, mdf_object.width, mdf_object.length, mdf_object.height, party_amount, percents);
}

void DefaultStorage::cout_info()
{
	std::cout << "    ІНФОРМАЦІЯ ПРО СКЛАД\n"
		         "| кількість МДФ      | -> " << get_storage_size() << "\n"
		         "| кількість обрізків | -> " << get_storage_size_cut() << "\n"
		         "| кількість цілих    | -> " << get_storage_size_whole() << "\n";
}

void DefaultStorage::cout_detail_info()
{
	std::cout << "детальна інформація:\n\n";

	if (main_storage.size() == 0)
		std::cout << "склад пустий.";

	else
	{
		int id = 0;
		for (auto i = storage_mdf_info.begin(); i != storage_mdf_info.end(); i++)
			std::cout << ++id << " | " << i->first << " -> " << i->second << " штук;\n";
	}
}