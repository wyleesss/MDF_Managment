#pragma once
#include <iostream>
#include <Windows.h>
#include <stack>
#include <string>
#include <map>

class MDF;

//функції для створення інформації про МДФ у вигляді тексту (для подальшого використання)
std::string mdf_info(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, bool is_original_size = true);
std::string mdf_info(const MDF& mdf_object);

class MDF
{
	std::string name;
	double price;

	int width, length, height;

	//якщо МДФ має початковий розмір
	bool is_original_size;

public:

	MDF(std::string name, double price, int width, int length, int height, bool is_original_size = true);

	std::string get_name();
	double get_price();

	int get_width();
	int get_length();
	int get_height();

	//повертає істину якщо МДФ є обрізком
	bool is_cut();

	//метод для обрізання МДФ
	void cut(int new_width, int new_length, int new_height);

	bool operator == (const MDF& mdf_object);

	friend std::string mdf_info(const MDF& mdf_object);

	friend class DefaultStorage;

	friend class CostStorage;
	friend class CapacityStorage;
};

//////////////////////////////////////////////////////////////////

class DefaultStorage
{
	//карта для збереження інформації про всі мдф на складі та їхньої кількості (для обліку та виводу інформації)
	std::map<std::string, int> storage_mdf_info;

protected:

	int mdf_max_width, mdf_max_length, mdf_max_height;
	std::stack<MDF> main_storage;

	//вилучення інформації про МДФ, кількість яких дорівнює 0
	virtual void update_storage_mdf_info();

public:

	DefaultStorage(int mdf_max_width, int mdf_max_length, int mdf_max_height);
	
	//повернути кількість всіх МДФ на складі
	size_t get_storage_size();

	//повернути кількість обрізків
	size_t get_storage_size_cut();

	//повернути кількість цілих частин
	size_t get_storage_size_whole();

	//прихід нової партії на склад
	virtual void new_arrival(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount);

	//прихід нової партії на склад в параметрах з об'єктом МДФ
	virtual void new_arrival(const MDF& mdf_object, int party_amount);

	//передача на виробництво, беручи листи зверху
	virtual void put_into_production_top(int party_amount);

	//передача на виробництво, беручи тільки обрізані листи зверху
	virtual void put_into_production_cut(int party_amount);

	//передача на виробництво, беручи тільки цілі листи зверху
	virtual void put_into_production_whole(int party_amount);

	//передача на виробництво, перебираючи тільки потрібні листи за властивостями
	virtual void put_into_production_special(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount);

	//передача на виробництво, перебираючи тільки потрібні листи за властивостями в параметрах з об'єктом МДФ
	void put_into_production_special(const MDF& mdf_object, int party_amount);

	//передача на виробництво, перебираючи тільки потрібні листи за розміром
	void put_into_production_special_size(int mdf_width, int mdf_length, int mdf_height, int party_amount);

	//передача на виробництво, перебираючи тільки потрібні листи за назвою
	void put_into_production_special_name(std::string mdf_name, int party_amount);

	//передача на виробництво, перебираючи тільки потрібні листи за ціною
	void put_into_production_special_price(double mdf_price, int party_amount);

	//повернення з виробництва обрізків
	virtual void return_from_production_cut(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount);

	//повернення з виробництва обрізків в параметрах з об'єктом МДФ
	void return_from_production_cut(const MDF& mdf_object, int party_amount);

	//повернення з виробництва цілих листів
	virtual void return_from_production_whole(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount, double percents);

	//повернення з виробництва цілих листів в параметрах з об'єктом МДФ
	void return_from_production_whole(const MDF& mdf_object, int party_amount, double percents);

	virtual void cout_info();

	virtual void cout_detail_info();
};