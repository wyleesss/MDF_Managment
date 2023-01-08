#pragma once
#include <iostream>
#include <Windows.h>
#include <stack>
#include <string>
#include <map>

class MDF;

//������� ��� ��������� ���������� ��� ��� � ������ ������ (��� ���������� ������������)
std::string mdf_info(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, bool is_original_size = true);
std::string mdf_info(const MDF& mdf_object);

class MDF
{
	std::string name;
	double price;

	int width, length, height;

	//���� ��� �� ���������� �����
	bool is_original_size;

public:

	MDF(std::string name, double price, int width, int length, int height, bool is_original_size = true);

	std::string get_name();
	double get_price();

	int get_width();
	int get_length();
	int get_height();

	//������� ������ ���� ��� � �������
	bool is_cut();

	//����� ��� �������� ���
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
	//����� ��� ���������� ���������� ��� �� ��� �� ����� �� ����� ������� (��� ����� �� ������ ����������)
	std::map<std::string, int> storage_mdf_info;

protected:

	int mdf_max_width, mdf_max_length, mdf_max_height;
	std::stack<MDF> main_storage;

	//��������� ���������� ��� ���, ������� ���� ������� 0
	virtual void update_storage_mdf_info();

public:

	DefaultStorage(int mdf_max_width, int mdf_max_length, int mdf_max_height);
	
	//��������� ������� ��� ��� �� �����
	size_t get_storage_size();

	//��������� ������� ������
	size_t get_storage_size_cut();

	//��������� ������� ����� ������
	size_t get_storage_size_whole();

	//������ ���� ���� �� �����
	virtual void new_arrival(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount);

	//������ ���� ���� �� ����� � ���������� � ��'����� ���
	virtual void new_arrival(const MDF& mdf_object, int party_amount);

	//�������� �� �����������, ������ ����� ������
	virtual void put_into_production_top(int party_amount);

	//�������� �� �����������, ������ ����� ������ ����� ������
	virtual void put_into_production_cut(int party_amount);

	//�������� �� �����������, ������ ����� ��� ����� ������
	virtual void put_into_production_whole(int party_amount);

	//�������� �� �����������, ����������� ����� ������ ����� �� �������������
	virtual void put_into_production_special(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount);

	//�������� �� �����������, ����������� ����� ������ ����� �� ������������� � ���������� � ��'����� ���
	void put_into_production_special(const MDF& mdf_object, int party_amount);

	//�������� �� �����������, ����������� ����� ������ ����� �� �������
	void put_into_production_special_size(int mdf_width, int mdf_length, int mdf_height, int party_amount);

	//�������� �� �����������, ����������� ����� ������ ����� �� ������
	void put_into_production_special_name(std::string mdf_name, int party_amount);

	//�������� �� �����������, ����������� ����� ������ ����� �� �����
	void put_into_production_special_price(double mdf_price, int party_amount);

	//���������� � ����������� ������
	virtual void return_from_production_cut(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount);

	//���������� � ����������� ������ � ���������� � ��'����� ���
	void return_from_production_cut(const MDF& mdf_object, int party_amount);

	//���������� � ����������� ����� �����
	virtual void return_from_production_whole(std::string mdf_name, double mdf_price, int mdf_width, int mdf_length, int mdf_height, int party_amount, double percents);

	//���������� � ����������� ����� ����� � ���������� � ��'����� ���
	void return_from_production_whole(const MDF& mdf_object, int party_amount, double percents);

	virtual void cout_info();

	virtual void cout_detail_info();
};