{
  "targets": [
    {
      "target_name": "Mt4Test",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
      "c++/src/view/MtDllTest.cpp",
      "c++/src/control/MtManager.cpp",

      #library
      "c++/include/library/napi/NapiObject.cpp",
      "c++/include/library/napi/NapiArray.cpp"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "c++/include",
        "c++"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}
