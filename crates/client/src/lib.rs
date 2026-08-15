#[no_mangle]
pub extern "C" fn Java_com_gongmi_callyscaves2_MainActivity_nativeInit(
    _env: *mut std::ffi::c_void,
    _class: *mut std::ffi::c_void,
) {
    println!("[callys-caves-2-rs] Native 64-bit library initialized!");
}
