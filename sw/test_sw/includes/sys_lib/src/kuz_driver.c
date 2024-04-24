#include <kuz_driver.h>

//static volatile struct KUZ_APB* kuz_item;
static uint32_t arr[4];

void kuz_init(){
	//kuz_item = (volatile struct KUZ_APB *)KUZ_BASE_ADDR;
	//kuz_item->KUZ_RST = 1;
	KUZ_RST = 1;
}

void kuz_rstn(){
	//kuz_item->KUZ_RST = 0;
	//kuz_item->KUZ_RST = 1;
	KUZ_RST = 0;
	KUZ_RST = 1;
}

void kuz_write_data(uint32_t *data){
	//while(kuz_item->KUZ_BUSY){
	while(KUZ_BUSY){

	}

	// kuz_item->KUZ_DATA_IN_0 = *data;
	// kuz_item->KUZ_DATA_IN_1 = *(data + 1);
	// kuz_item->KUZ_DATA_IN_2 = *(data + 2);
	// kuz_item->KUZ_DATA_IN_3 = *(data + 3);

    // kuz_item->KUZ_REQ = 1;
	KUZ_DATA_IN_0 = *data;
	KUZ_DATA_IN_1 = *(data + 1);
	KUZ_DATA_IN_2 = *(data + 2);
	KUZ_DATA_IN_3 = *(data + 3);

    KUZ_REQ = 1;
}

uint32_t * kuz_read_data(){
	// while(!kuz_item->KUZ_VALID){

	// }
	// arr[0] = kuz_item->KUZ_DATA_OUT_0;
	// arr[1] = kuz_item->KUZ_DATA_OUT_1;
	// arr[2] = kuz_item->KUZ_DATA_OUT_2;
	// arr[3] = kuz_item->KUZ_DATA_OUT_3;

	// kuz_item->KUZ_ACK = 1;

	while(!KUZ_VALID){

	}
	arr[0] = KUZ_DATA_OUT_0;
	arr[1] = KUZ_DATA_OUT_1;
	arr[2] = KUZ_DATA_OUT_2;
	arr[3] = KUZ_DATA_OUT_3;

	KUZ_ACK = 1;
	return arr;
}

/*void kuz_write_data(int *data){
	kuz_item.KUZ_REG_WRITE_DATA_0 = *data;
	kuz_item.KUZ_REG_WRITE_DATA_1 = *(data + 1);
	kuz_item.KUZ_REG_WRITE_DATA_2 = *(data + 2);
	kuz_item.KUZ_REG_WRITE_DATA_3 = *(data + 3);
}*/




/*int kuz_read_data(){
	uint32_t arr[4];
	arr[0] = KUZ_REG_READ_DATA_0;
	arr[1] = KUZ_REG_READ_DATA_1;
	arr[2] = KUZ_REG_READ_DATA_2;
	arr[3] = KUZ_REG_READ_DATA_3;
	return *arr[0];
}*/


/*int kuz_read_status(){
	return kuz_item.KUZ_REG_READ_STATUS;
}

int kuz_read_idle_status(){
	volatile int status = kuz_read_status();
	if (status = KUZ_STATUS_IDLE)
	{
		return 1;
	} else {
		return 0;
	}
}

int kuz_read_key_phase_status(){
	volatile int status = kuz_read_status();
	if (status = KUZ_STATUS_KEY_PHASE)
	{
		return 1;
	} else {
		return 0;
	}
}

int kuz_read_S_phase_status(){
	volatile int status = kuz_read_status();
	if (status = KUZ_STATUS_S_PHASE)
	{
		return 1;
	} else {
		return 0;
	}
}

int kuz_read_l_phase_status(){
	volatile int status = kuz_read_status();
	if (status = KUZ_STATUS_L_PHASE)
	{
		return 1;
	} else {
		return 0;
	}
}

int kuz_read_finish_status(){
	volatile int status = kuz_read_status();
	if (status = KUZ_STATUS_FINISH)
	{
		return 1;
	} else {
		return 0;
	}
}*/