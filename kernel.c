void kernel_entry() {
    char* test = (char*)(0xB8000);
    *test = ' ';
}
