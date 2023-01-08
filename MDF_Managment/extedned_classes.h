#pragma once
#include "basic_classes.h"

class CostStorage :public DefaultStorage
{
	double storage_cost;

	//додатково зберігаємо ще інформацію про вартість
	std::map<std::string, std::pair<int, double>> storage_mdf_info;

	void update_storage_mdf_info() override;

public:

	//оскільки підклас не успадковує перевантажені методи
	using DefaultStorage::new_arrival;
	using DefaultStorage::put_into_production_special;
	using DefaultStorage::return_from_production_cut;
	using DefaultStorage::return_from_production_whole;

	CostStorage(int mdf_max_width, int mdf_max_length, int mdf_max_height);

	//повернути вартість продукції складу
	double get_storage_cost();

	void new_arrival(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount) override;

	void put_into_production_top(int party_amount) override;

	void put_into_production_cut(int party_amount) override;

	void put_into_production_whole(int party_amount) override;

	void put_into_production_special(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount) override;

	void return_from_production_cut(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount) override;

	void return_from_production_whole(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount, double percents) override;

	void cout_info() override;

	void cout_detail_info() override;

};

class CapacityStorage :public DefaultStorage
{
	//поле для зберігання максимальної місткості складу (метри кубічні)
	const double storage_max_capacity;

	//поле для зберігання поточного зайнятого об'єму складу
	double current_occupied_area;

	//додатково зберігаємо й інформацію про об'єм
	std::map<std::string, std::pair<int, double>> storage_mdf_info;

	void update_storage_mdf_info() override;

public:

	using DefaultStorage::new_arrival;
	using DefaultStorage::put_into_production_special;
	using DefaultStorage::return_from_production_cut;
	using DefaultStorage::return_from_production_whole;

	CapacityStorage(int mdf_max_width, int mdf_max_length, int mdf_max_height, double storage_max_capacity);

	//повернути місткість складу
	double get_storage_max_capacity();

	//повернути зайнятий об'єм
	double get_storage_occupied_area();

	//повернути зайняте місце складу у відсотках
	double get_storage_occupied_area_percentage();

	void new_arrival(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount) override;

	void put_into_production_top(int party_amount) override;

	void put_into_production_cut(int party_amount) override;

	void put_into_production_whole(int party_amount) override;

	void put_into_production_special(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount) override;

	void return_from_production_cut(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount) override;

	void return_from_production_whole(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount, double percents) override;

	void cout_info() override;

	void cout_detail_info() override;
};