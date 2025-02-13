#include <stdint.h>
uint64_t cal_r12(uint64_t r12, uint64_t r13, uint64_t r14, uint64_t r15){
    uint64_t rax=0,rbx=0;
    uint64_t v0=2616514329260088143ull;
    uint64_t v1=1237891274917891239ull;
    uint64_t v2=1892739ull;
    uint64_t v3=r12;
    uint64_t v4=v2+v3;
    uint64_t v5=v1^v4;
    uint64_t v6=v0^v5;
    uint64_t v7=8502251781212277489ull;
    uint64_t v8=1209847170981118947ull;
    uint64_t v9=8971237ull;
    uint64_t v10=r13;
    uint64_t v11=v9+v10;
    uint64_t v12=v8^v11;
    uint64_t v13=v7^v12;
    uint64_t v14=v6|v13;
    uint64_t v15=2451795628338718684ull;
    uint64_t v16=1098791727398412397ull;
    uint64_t v17=1512312ull;
    uint64_t v18=r14;
    uint64_t v19=v17+v18;
    uint64_t v20=v16^v19;
    uint64_t v21=v15^v20;
    uint64_t v22=v14|v21;
    uint64_t v23=8722213363631027234ull;
    uint64_t v24=1890878197237214971ull;
    uint64_t v25=9123704ull;
    uint64_t v26=r15;
    uint64_t v27=v25+v26;
    uint64_t v28=v24^v27;
    uint64_t v29=v23^v28;
    uint64_t v30=v22|v29;
    return v30;
}

