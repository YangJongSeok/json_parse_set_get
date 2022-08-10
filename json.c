#include <stdio.h>
// 에러 아님 / ../../lib/json 폴더 안에 있는 라이브러리 이용중, 라이브러리의 헤더명, makefile에서 선언
#include "json.h"

int main(int argc, char** argv) {

    JSON_Value *rootValue;
    JSON_Object *rootObject;
    
    rootValue = json_parse_file("example.json");
    rootObject = json_value_get_object(rootValue);    // JSON_Value에서 JSON_Object를 얻음
    
    // 객체에 키를 추가하고 문자열 저장
    json_object_set_string(rootObject, "Title", "TOPGUN");
    json_object_set_string(rootObject, "Year", "2022");
    // json_object_set_string(rootObject, "Runtime", "148");

    // json_serialize_to_file_pretty(rootValue, "example.json");

// ******************** JSON String Value 가져오기

    printf("Title [%s]\n", json_object_get_string(rootObject, "Title"));
    printf("Year [%s]\n", json_object_get_string(rootObject, "Year"));
    printf("Runtile [%s]\n", json_object_get_string(rootObject, "Runtime"));

// ******************** JSON Array 사용
    int i = 0;
    JSON_Array *array = json_object_get_array(rootObject, "Actors");
    for(i = 0; i < json_array_get_count(array); i++) {
        printf("Actors [%s]\n", json_array_get_string(array, i));
    }
    printf("ABC [%s]\n", json_object_get_string(rootObject, "ABC"));

    // 없는 key value는 null
    printf("DDD [%s]\n", json_object_get_string(rootObject, "DDD"));
    json_value_free(rootValue);

// ******************** JSON value 비워놓고 사용시 segment error
    // printf("Value Free After\n");
    // printf("Title [%s]\n", json_object_get_string(rootObject, "Title"));

    return 0;
}
