#include <gtest/gtest.h>
#include "fanctions of remove.h"
#include "conio.h"

TEST(RemElemInEnd, can_remove_others_elem_in_elem){
	CNode *list = 0;	
	
	for (int i = 0; i < 5; i++){
		CNode *node = new CNode;
		node->next = list;
		node->date = i;
		list = node;
	}

	(*list)=RemElemInEnd(list,5,2);
	
	EXPECT_TRUE(list->date == 4);
	list = list->next;

	EXPECT_TRUE(list->date == 3);
	list = list->next;

	EXPECT_TRUE(list->date == 2);
	list = list->next;

	EXPECT_TRUE(list->date == 0);
	list=list->next;

	EXPECT_TRUE(list ==0);


	}


TEST(RemElemInEnd, can_remove_later_elem_in_end){
	CNode *list = 0;

	for (int i = 0; i < 5; i++){
		CNode *node = new CNode;
		node->next = list;
		node->date = i;
		list = node;
	}

	(*list) = RemElemInEnd(list, 5, 5);

	EXPECT_TRUE(list->date == 3);
	list = list->next;

	EXPECT_TRUE(list->date == 2);
	list = list->next;

	EXPECT_TRUE(list->date == 1 );
	list = list->next;

	EXPECT_TRUE(list->date == 0);
	list = list->next;

	EXPECT_TRUE(list == 0);


}


TEST(RemElemInEnd, can_remove_fist_elem_in_end){
	CNode *list = 0;
	for (int i = 0; i < 5; i++){
		CNode *node = new CNode;
		node->next = list;
		node->date = i;
		list = node;
	}

	(*list) = RemElemInEnd(list, 5, 1);

	EXPECT_TRUE(list->date == 4);
	list = list->next;

	EXPECT_TRUE(list->date == 3);
	list = list->next;

	EXPECT_TRUE(list->date == 2);
	list = list->next;

	EXPECT_TRUE(list->date == 1);
	list = list->next;

	EXPECT_TRUE(list == 0);


}
TEST(RemElemInEnd, throws_when_non_correct_possition_of_element){
	CNode *list = 0;
	for (int i = 0; i < 5; i++){
		CNode *node = new CNode;
		node->next = list;
		node->date = i;
		list = node;
	}
		
	ASSERT_ANY_THROW(RemElemInEnd(list, 5, 10));

}

////////////////

TEST(RemRepeatElem, can_remove_repeat_elem_in_middle){
	CNode *list = 0;

	for (int i = 0; i < 5; i++){
		CNode *node = new CNode;
		node->next = list;
		node->date = i;
		list = node;
	}
	list->date = 3;
	RemRepeatElem(list);

	EXPECT_TRUE(list->date == 3);
	list = list->next;

	EXPECT_TRUE(list->date == 2);
	list = list->next;

	EXPECT_TRUE(list->date == 1);
	list = list->next;

	EXPECT_TRUE(list->date == 0);
	list = list->next;

	EXPECT_TRUE(list == 0);


}

TEST(RemRepeatElem, can_remove_repeat_two_elem_in_end){
	CNode *list = 0;

	for (int i = 0; i < 2; i++){
		CNode *node = new CNode;
		node->next = list;
		node->date = 1;
		list = node;
	}
	CNode *list1 = list;

	RemRepeatElem(list);

	EXPECT_TRUE(list1->date == 1);

	list1= list1->next;	
	EXPECT_TRUE(list1 == 0);

}


TEST(RemRepeatElem, can_work_correct_with_empty_spisok){
	CNode *list = 0;

	RemRepeatElem(list);

	EXPECT_TRUE(list == 0);


}

TEST(RemRepeatElem, can_remove_when_all_repeat_elem_in_spisok){
	CNode *list = 0;

	for (int i = 0; i < 3; i++){
		CNode *node = new CNode;
		node->next = list;
		node->date = 1;
		list = node;
	}
	CNode *list1 = list;
	RemRepeatElem(list);

	EXPECT_TRUE(list1->date == 1);

	list1 = list1->next;

	EXPECT_TRUE(list1 == 0);


}
TEST(RemRepeatElem, can_remove_when_few_repeat_elem_in_spisok){
	CNode *list = 0;

	for (int i = 0; i <6 ; i++){
		CNode *node = new CNode;
		node->next = list;
		if (i < 3) node->date = 1;
		else
			node->date = 2;
		list = node;
	}
	list->date = 3;
	CNode *list1 = list;

	RemRepeatElem(list);

	EXPECT_TRUE(list1->date == 3);

	list1 = list1->next;
	EXPECT_TRUE(list1->date == 2);

	list1 = list1->next;
	EXPECT_TRUE(list1->date == 1);

	
	list1 = list1->next;
	EXPECT_TRUE(list1 == 0);


}



int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
  
}
