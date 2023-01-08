#include "extedned_classes.h"

CostStorage::CostStorage(int mdf_max_width, int mdf_max_length, int mdf_max_height) 
	:DefaultStorage(mdf_max_width, mdf_max_length, mdf_max_height)
{
	storage_cost = 0;
}

double CostStorage::get_storage_cost() { return storage_cost; }

void CostStorage::update_storage_mdf_info()
{
	for (auto i = storage_mdf_info.begin(); i != storage_mdf_info.end(); i++)
		if (i->second.first == 0)
		{
			storage_mdf_info.erase(i);
			update_storage_mdf_info();
			return;
		}
}

void CostStorage::new_arrival(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount)
{
	try
	{
		if (party_amount <= 0 || party_amount % 25 != 0)
			throw std::string("*облік за вартістю\n"
				              "( ! помилка )| постачання нової партії на склад МДФ |\n"
				              "             | (i) -> кількість штук МДФ в партії незадовільна.\n\n");

		if (mdf_width > mdf_max_width || mdf_length > mdf_max_length || mdf_height > mdf_max_height)
			throw std::string("*облік за вартістю\n"
				              "( ! помилка )| постачання нової партії на склад МДФ |\n"
			         	      "             | (i) -> розмір МДФ завеликий.\n\n");

		if (mdf_width < 100 || mdf_length < 100)
			throw std::string("*облік за вартістю\n"
				              "( ! помилка )| постачання нової партії на склад МДФ |\n"
				              "             | (i) -> розмір МДФ замалий.\n\n");

		std::string current_mdf_info = mdf_info(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height);
		std::map<std::string, std::pair<int, double>>::iterator it = storage_mdf_info.find(current_mdf_info);

		if (it != storage_mdf_info.end())
		{
			//додаємо спочатку кількість
			it->second.first += party_amount;

			//згодом вартість
			it->second.second += mdf_price * party_amount;
		}

		else
			storage_mdf_info.emplace(current_mdf_info, std::pair<int, double>(party_amount, mdf_price * party_amount));

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

		//додаємо ціну партії до ціни всього складу
		storage_cost += mdf_price * party_amount;

		throw std::string("*облік за вартістю\n"
			              "( # )| постачання нової партії на склад МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

void CostStorage::put_into_production_top(int party_amount)
{
	try
	{
		if (main_storage.size() < party_amount)
			throw std::string("*облік за вартістю\n"
				              "( ! помилка )| передача на виробництво МДФ |\n"
				              "             | (i) -> на складі не вистачає МДФ, щоб виконати передачу на визначену кількість.\n\n");

		for (int i = 0; i < party_amount; i++)
		{
			std::string current_mdf_info = mdf_info(main_storage.top());
			storage_mdf_info.find(current_mdf_info)->second.first--;
			storage_mdf_info.find(current_mdf_info)->second.second -= main_storage.top().price;

			//віднімаємо ціну кожної МДФ від ціни всього складу
			storage_cost -= main_storage.top().price;

			main_storage.pop();
		}

		update_storage_mdf_info();

		throw std::string("*облік за вартістю\n"
			              "( # )| передача на виробництво МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

void CostStorage::put_into_production_cut(int party_amount)
{
	try
	{
		if (get_storage_size_cut() < party_amount)
			throw std::string("*облік за вартістю\n"
				              "( ! помилка )| передача на виробництво обрізків МДФ |\n"
				              "             | (i) -> на складі не вистачає обрізків МДФ, щоб виконати передачу на визначену кількість.\n\n");

		for (int i = 0; i < party_amount; i++)
		{
			std::string current_mdf_info = mdf_info(main_storage.top());
			storage_mdf_info.find(current_mdf_info)->second.first--;
			storage_mdf_info.find(current_mdf_info)->second.second -= main_storage.top().price;

			storage_cost -= main_storage.top().price;

			main_storage.pop();
		}

		update_storage_mdf_info();

		throw std::string("*облік за вартістю\n"
			              "( # )| передача на виробництво обрізків МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

void CostStorage::put_into_production_whole(int party_amount)
{
	try
	{
		if (get_storage_size_whole() < party_amount)
			throw std::string("*облік за вартістю\n"
				              "( ! помилка )| передача на виробництво цілих МДФ |\n"
				              "             | (i) -> на складі не вистачає цілих МДФ, щоб виконати передачу на визначену кількість.\n\n");

		if (main_storage.top().is_cut())
		{
			std::stack<MDF> temporary_for_swap;

			while (main_storage.top().is_cut())
			{
				temporary_for_swap.push(main_storage.top());
				main_storage.pop();
			}

			for (int i = 0; i < party_amount; i++)
			{
				std::string current_mdf_info = mdf_info(main_storage.top());
				storage_mdf_info.find(current_mdf_info)->second.first--;
				storage_mdf_info.find(current_mdf_info)->second.second -= main_storage.top().price;

				storage_cost -= main_storage.top().price;

				main_storage.pop();
			}

			update_storage_mdf_info();

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
				storage_mdf_info.find(current_mdf_info)->second.first--;
				storage_mdf_info.find(current_mdf_info)->second.second -= main_storage.top().price;

				storage_cost -= main_storage.top().price;

				main_storage.pop();
			}

			update_storage_mdf_info();
		}

		throw std::string("*облік за вартістю\n"
			              "( # )| передача на виробництво цілих МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

void CostStorage::put_into_production_special(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount)
{
	try
	{
		std::stack<MDF> not_needed_elements, needed_elements;

		while (!main_storage.empty())
		{
			if (main_storage.top() == MDF(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height))
				needed_elements.push(main_storage.top());

			else
				not_needed_elements.push(main_storage.top());

			main_storage.pop();
		}

		if (needed_elements.size() < party_amount)
			throw std::string("*облік за вартістю\n"
				              "( ! помилка )| передача на виробництво певних МДФ |\n"
				              "             | (i) -> на складі не вистачає МДФ з даними властивостями, щоб виконати передачу на визначену кількість.\n\n");

		for (int i = 0; i < party_amount; i++)
		{
			std::string current_mdf_info = mdf_info(needed_elements.top());
			storage_mdf_info.find(current_mdf_info)->second.first--;
			storage_mdf_info.find(current_mdf_info)->second.second -= needed_elements.top().price;

			storage_cost -= needed_elements.top().price;

			needed_elements.pop();
		}

		update_storage_mdf_info();

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

		throw std::string("*облік за вартістю\n"
			              "( # )| передача на виробництво певних МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

void CostStorage::return_from_production_cut(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount)
{
	try
	{
		if (mdf_width >= mdf_max_width || mdf_length >= mdf_max_length || mdf_height >= mdf_max_height)
			throw std::string("*облік за вартістю\n"
				              "( ! помилка )| повернення з виробництва обрізків МДФ |\n"
				              "             | (i) -> розмір МДФ завеликий.\n\n");

		if (mdf_width < 100 || mdf_length < 100)
			throw std::string("*облік за вартістю\n"
				              "( ! помилка )| повернення з виробництва обрізків МДФ |\n"
				              "             | (i) -> розмір МДФ замалий.\n\n");

		std::string current_mdf_info = mdf_info(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height, false);
		std::map<std::string, std::pair<int, double>>::iterator it = storage_mdf_info.find(current_mdf_info);

		if (it != storage_mdf_info.end())
		{
			it->second.first += party_amount;
			it->second.second += mdf_price * party_amount;
		}

		else
			storage_mdf_info.emplace(current_mdf_info, std::pair<int, double>(party_amount, mdf_price * party_amount));

		for (int i = 0; i < party_amount; i++)
			main_storage.push(MDF(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height, false));

		storage_cost += mdf_price * party_amount;

		throw std::string("*облік за вартістю\n"
			              "( # )| повернення з виробництва обрізків МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

void CostStorage::return_from_production_whole(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount, double percents)
{
	try
	{
		if (mdf_width > mdf_max_width || mdf_length > mdf_max_length || mdf_height > mdf_max_height)
			throw std::string("*облік за вартістю\n"
				              "( ! помилка )| повернення з виробництва цілих МДФ |\n"
				              "             | (i) -> розмір МДФ завеликий.\n\n");

		if (mdf_width < 100 || mdf_length < 100)
			throw std::string("*облік за вартістю\n"
				              "( ! помилка )| повернення з виробництва цілих МДФ |\n"
				              "             | (i) -> розмір МДФ замалий.\n\n");

		mdf_price -= mdf_price / 100 * percents;

		std::string current_mdf_info = mdf_info(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height);
		std::map<std::string, std::pair<int, double>>::iterator it = storage_mdf_info.find(current_mdf_info);

		if (it != storage_mdf_info.end())
		{
			it->second.first += party_amount;
			it->second.second += mdf_price * party_amount;
		}

		else
			storage_mdf_info.emplace(current_mdf_info, std::pair<int, double>(party_amount, mdf_price * party_amount));


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

		storage_cost += mdf_price * party_amount;

		throw std::string("*облік за вартістю\n"
			              "( # )| повернення з виробництва цілих МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

void CostStorage::cout_info()
{
	std::cout << "    ІНФОРМАЦІЯ ПРО СКЛАД\n"
		"| вартість продукції складу | -> " << storage_cost << "\n"
		"| кількість МДФ             | -> " << get_storage_size() << "\n"
		"| кількість обрізків        | -> " << get_storage_size_cut() << "\n"
		"| кількість цілих           | -> " << get_storage_size_whole() << "\n";
}

void CostStorage::cout_detail_info()
{
	std::cout << "детальна інформація:\n\n";

	if (main_storage.size() == 0)
		std::cout << "склад пустий.";

	else
	{
		int id = 0;
		for (auto i = storage_mdf_info.begin(); i != storage_mdf_info.end(); i++)
		{
			std::cout << ++id << " | " << i->first << " -> " << i->second.first << " штук\n  : сумарна вартість -> " << i->second.second << ";\n"
				"-      -      -\n";
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CapacityStorage::CapacityStorage(int mdf_max_width, int mdf_max_length, int mdf_max_height, double storage_max_capacity)
	:DefaultStorage(mdf_max_width, mdf_max_length, mdf_max_height), storage_max_capacity(storage_max_capacity)
{
	current_occupied_area = 0;
}

void CapacityStorage::update_storage_mdf_info()
{
	for (auto i = storage_mdf_info.begin(); i != storage_mdf_info.end(); i++)
		if (i->second.first == 0)
		{
			storage_mdf_info.erase(i);
			update_storage_mdf_info();
			return;
		}
}

//повернути місткість складу
double CapacityStorage::get_storage_max_capacity() { return storage_max_capacity; }

//повернути зайнятий об'єм
double CapacityStorage::get_storage_occupied_area() { return current_occupied_area; }

//повернути зайняту площу складу у відсотках
double CapacityStorage::get_storage_occupied_area_percentage() { return current_occupied_area * 100 / storage_max_capacity; }

void CapacityStorage::new_arrival(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount)
{
	try
	{
		if (party_amount <= 0 || party_amount % 25 != 0)
			throw std::string("*облік за розміром\n"
				              "( ! помилка )| постачання нової партії на склад МДФ |\n"
				              "             | (i) -> кількість штук МДФ в партії незадовільна.\n\n");

		if (mdf_width > mdf_max_width || mdf_length > mdf_max_length || mdf_height > mdf_max_height)
			throw std::string("*облік за розміром\n"
				              "( ! помилка )| постачання нової партії на склад МДФ |\n"
			         	      "             | (i) -> розмір МДФ завеликий.\n\n");

		if (mdf_width < 100 || mdf_length < 100)
			throw std::string("*облік за розміром\n"
				              "( ! помилка )| постачання нової партії на склад МДФ |\n"
				              "             | (i) -> розмір МДФ замалий.\n\n");

		//враховуючи, що розмір МДФ у міліметрах, визначаємо об'єм та переводимо в метри кубічні
		if ((static_cast<long long>(mdf_width * mdf_length * mdf_height) / 1000000000.f) * party_amount + current_occupied_area > storage_max_capacity)
			throw std::string("*облік за розміром\n"
			            	  "( ! помилка )| постачання нової партії на склад МДФ |\n"
				              "             | (i) -> не вистачає вільного місця на складі\n\n");

		std::string current_mdf_info = mdf_info(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height);
		std::map<std::string, std::pair<int, double>>::iterator it = storage_mdf_info.find(current_mdf_info);

		if (it != storage_mdf_info.end())
		{
			//додаємо спочатку кількість
			it->second.first += party_amount;

			//згодом об'єм
			it->second.second += (static_cast<long long>(mdf_width * mdf_length * mdf_height) / 1000000000.f) * party_amount;
		}

		else
			storage_mdf_info.emplace(current_mdf_info, std::pair<int, double>(party_amount, (static_cast<long long>(mdf_width * mdf_length * mdf_height) / 1000000000.f) * party_amount));

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

		//додаємо об'єм партії до зайнятого об'єму всього складу
		current_occupied_area += (static_cast<long long>(mdf_width * mdf_length * mdf_height) / 1000000000.f) * party_amount;

		throw std::string("*облік за розміром\n"
			              "( # )| постачання нової партії на склад МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

void CapacityStorage::put_into_production_top(int party_amount)
{
	try
	{
		if (main_storage.size() < party_amount)
			throw std::string("*облік за розміром\n"
				              "( ! помилка )| передача на виробництво МДФ |\n"
				              "             | (i) -> на складі не вистачає МДФ, щоб виконати передачу на визначену кількість.\n\n");

		for (int i = 0; i < party_amount; i++)
		{
			std::string current_mdf_info = mdf_info(main_storage.top());
			storage_mdf_info.find(current_mdf_info)->second.first--;
			storage_mdf_info.find(current_mdf_info)->second.second -= (static_cast<long long>(main_storage.top().width * main_storage.top().length * main_storage.top().height) / 1000000000.f) * party_amount;

			//віднімаємо об'єм кожної МДФ від зайнятого об'єму всього складу
			current_occupied_area -= (static_cast<long long>(main_storage.top().width * main_storage.top().length * main_storage.top().height) / 1000000000.f) * party_amount;

			main_storage.pop();
		}

		update_storage_mdf_info();

		throw std::string("*облік за розміром\n"
			              "( # )| передача на виробництво МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

void CapacityStorage::put_into_production_cut(int party_amount)
{
	try
	{
		if (get_storage_size_cut() < party_amount)
			throw std::string("*облік за розміром\n"
				              "( ! помилка )| передача на виробництво обрізків МДФ |\n"
				              "             | (i) -> на складі не вистачає обрізків МДФ, щоб виконати передачу на визначену кількість.\n\n");

		for (int i = 0; i < party_amount; i++)
		{
			std::string current_mdf_info = mdf_info(main_storage.top());
			storage_mdf_info.find(current_mdf_info)->second.first--;
			storage_mdf_info.find(current_mdf_info)->second.second -= (static_cast<long long>(main_storage.top().width * main_storage.top().length * main_storage.top().height) / 1000000000.f) * party_amount;

			current_occupied_area -= (static_cast<long long>(main_storage.top().width * main_storage.top().length * main_storage.top().height) / 1000000000.f) * party_amount;

			main_storage.pop();
		}

		update_storage_mdf_info();

		throw std::string("*облік за розміром\n"
			              "( # )| передача на виробництво обрізків МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

void CapacityStorage::put_into_production_whole(int party_amount)
{
	try
	{
		if (get_storage_size_whole() < party_amount)
			throw std::string("*облік за розміром\n"
				              "( ! помилка )| передача на виробництво цілих МДФ |\n"
				              "             | (i) -> на складі не вистачає цілих МДФ, щоб виконати передачу на визначену кількість.\n\n");

		if (main_storage.top().is_cut())
		{
			std::stack<MDF> temporary_for_swap;

			while (main_storage.top().is_cut())
			{
				temporary_for_swap.push(main_storage.top());
				main_storage.pop();
			}

			for (int i = 0; i < party_amount; i++)
			{
				std::string current_mdf_info = mdf_info(main_storage.top());
				storage_mdf_info.find(current_mdf_info)->second.first--;
				storage_mdf_info.find(current_mdf_info)->second.second -= (static_cast<long long>(main_storage.top().width * main_storage.top().length * main_storage.top().height) / 1000000000.f) * party_amount;

				current_occupied_area -= (static_cast<long long>(main_storage.top().width * main_storage.top().length * main_storage.top().height) / 1000000000.f) * party_amount;

				main_storage.pop();
			}

			update_storage_mdf_info();

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
				storage_mdf_info.find(current_mdf_info)->second.first--;
				storage_mdf_info.find(current_mdf_info)->second.second -= (static_cast<long long>(main_storage.top().width * main_storage.top().length * main_storage.top().height) / 1000000000.f) * party_amount;

				current_occupied_area -= (static_cast<long long>(main_storage.top().width * main_storage.top().length * main_storage.top().height) / 1000000000.f) * party_amount;

				main_storage.pop();
			}

			update_storage_mdf_info();
		}

		throw std::string("*облік за розміром\n"
			              "( # )| передача на виробництво цілих МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

void CapacityStorage::put_into_production_special(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount)
{
	try
	{
		std::stack<MDF> not_needed_elements, needed_elements;

		while (!main_storage.empty())
		{
			if (main_storage.top() == MDF(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height))
				needed_elements.push(main_storage.top());

			else
				not_needed_elements.push(main_storage.top());

			main_storage.pop();
		}

		if (needed_elements.size() < party_amount)
			throw std::string("*облік за розміром\n"
				              "( ! помилка )| передача на виробництво певних МДФ |\n"
				              "             | (i) -> на складі не вистачає МДФ з даними властивостями, щоб виконати передачу на визначену кількість.\n\n");

		for (int i = 0; i < party_amount; i++)
		{
			std::string current_mdf_info = mdf_info(needed_elements.top());
			storage_mdf_info.find(current_mdf_info)->second.first--;
			storage_mdf_info.find(current_mdf_info)->second.second -= (static_cast<long long>(needed_elements.top().width * needed_elements.top().length * needed_elements.top().height) / 1000000000.f);

			current_occupied_area -= (static_cast<long long>(needed_elements.top().width * needed_elements.top().length * needed_elements.top().height) / 1000000000.f);

			needed_elements.pop();
		}

		update_storage_mdf_info();

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

		throw std::string("*облік за розміром\n"
			              "( # )| передача на виробництво певних МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

void CapacityStorage::return_from_production_cut(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount)
{
	try
	{
		if (mdf_width >= mdf_max_width || mdf_length >= mdf_max_length || mdf_height >= mdf_max_height)
			throw std::string("*облік за розміром\n"
				              "( ! помилка )| повернення з виробництва обрізків МДФ |\n"
				              "             | (i) -> розмір МДФ завеликий.\n\n");

		if (mdf_width < 100 || mdf_length < 100)
			throw std::string("*облік за розміром\n"
				              "( ! помилка )| повернення з виробництва обрізків МДФ |\n"
				              "             | (i) -> розмір МДФ замалий.\n\n");

		if ((static_cast<long long>(mdf_width * mdf_length * mdf_height) / 1000000000.f) * party_amount + current_occupied_area > storage_max_capacity)
			throw std::string("*облік за розміром\n"
				              "( ! помилка )| повернення з виробництва обрізків МДФ |\n"
				              "             | (i) -> не вистачає вільного місця на складі\n\n");

		std::string current_mdf_info = mdf_info(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height, false);
		std::map<std::string, std::pair<int, double>>::iterator it = storage_mdf_info.find(current_mdf_info);

		if (it != storage_mdf_info.end())
		{
			it->second.first += party_amount;
			it->second.second += (static_cast<long long>(mdf_width * mdf_length * mdf_height) / 1000000000.f) * party_amount;
		}

		else
			storage_mdf_info.emplace(current_mdf_info, std::pair<int, double>(party_amount, (static_cast<long long>(mdf_width * mdf_length * mdf_height) / 1000000000.f) * party_amount));

		for (int i = 0; i < party_amount; i++)
			main_storage.push(MDF(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height, false));

		current_occupied_area += (static_cast<long long>(mdf_width * mdf_length * mdf_height) / 1000000000.f) * party_amount;

		throw std::string("*облік за розміром\n"
			              "( # )| повернення з виробництва обрізків МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

void CapacityStorage::return_from_production_whole(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount, double percents)
{
	try
	{
		if (mdf_width > mdf_max_width || mdf_length > mdf_max_length || mdf_height > mdf_max_height)
			throw std::string("*облік за розміром\n"
				              "( ! помилка )| повернення з виробництва цілих МДФ |\n"
				              "             | (i) -> розмір МДФ завеликий.\n\n");

		if (mdf_width < 100 || mdf_length < 100)
			throw std::string("*облік за розміром\n"
				              "( ! помилка )| повернення з виробництва цілих МДФ |\n"
				              "             | (i) -> розмір МДФ замалий.\n\n");

		if ((static_cast<long long>(mdf_width * mdf_length * mdf_height) / 1000000000.f) * party_amount + current_occupied_area > storage_max_capacity)
			throw std::string("*облік за розміром\n"
				              "( ! помилка )| повернення з виробництва цілих МДФ |\n"
				              "             | (i) -> не вистачає вільного місця на складі\n\n");

		mdf_price -= mdf_price / 100 * percents;

		std::string current_mdf_info = mdf_info(mdf_name, mdf_price, mdf_width, mdf_length, mdf_height);
		std::map<std::string, std::pair<int, double>>::iterator it = storage_mdf_info.find(current_mdf_info);

		if (it != storage_mdf_info.end())
		{
			it->second.first += party_amount;
			it->second.second += (static_cast<long long>(mdf_width * mdf_length * mdf_height) / 1000000000.f) * party_amount;
		}

		else
			storage_mdf_info.emplace(current_mdf_info, std::pair<int, double>(party_amount, (static_cast<long long>(mdf_width * mdf_length * mdf_height) / 1000000000.f) * party_amount));


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

		current_occupied_area += (static_cast<long long>(mdf_width * mdf_length * mdf_height) / 1000000000.f) * party_amount;

		throw std::string("*облік за розміром\n"
			              "( # )| повернення з виробництва цілих МДФ |\n"
			              "     | (i) -> виконано успішно.\n\n");
	}
	catch (std::string& ex)
	{
		std::cout << ex;
	}
}

void CapacityStorage::cout_info()
{
	std::cout << "    ІНФОРМАЦІЯ ПРО СКЛАД\n"
		"| максимальна вмістимість складу | -> " << storage_max_capacity << " м^3" << "\n"
		"| зайнятий об'єм складу          | -> " << current_occupied_area << " м^3" << "\n"
		"| зайнятий об'єм складу (%)      | -> " << get_storage_occupied_area_percentage() << "%" << "\n"
		"| кількість МДФ                  | -> " << get_storage_size() << "\n"
		"| кількість обрізків             | -> " << get_storage_size_cut() << "\n"
		"| кількість цілих                | -> " << get_storage_size_whole() << "\n";
}

void CapacityStorage::cout_detail_info()
{
	std::cout << "детальна інформація:\n\n";

	if (main_storage.size() == 0)
		std::cout << "склад пустий.";

	else
	{
		int id = 0;
		for (auto i = storage_mdf_info.begin(); i != storage_mdf_info.end(); i++)
		{
			std::cout << ++id << " | " << i->first << " -> " << i->second.first << " штук\n  : сумарний об'єм -> " << i->second.second << " м^3;\n"
				"-      -      -\n";
		}
	}
}