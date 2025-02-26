{
  'targets': [
    {
      'target_name': 'diskusage',
      'include_dirs': [ "<!@(node -p \"require('node-addon-api').include\")" ],
      'sources': [
        'src/main.cpp',
        'src/diskusage.h',
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      'cflags' : [
        '-std=c++11',
        '-D_GLIBCXX_USE_CXX11_ABI=0'
      ],
      'conditions': [
        ['OS=="win"', {
          'sources': [
            'src/diskusage_win.cpp',
          ],
          'defines': [
            'UNICODE',
            'WIN32_LEAN_AND_MEAN',
            'NOMINMAX'
          ],
          'msvs_settings': {
            'VCCLCompilerTool': {
              'ExceptionHandling': '1'
            }
          }
        }],
        ['OS not in ["win"]', {
          'sources': [
            'src/diskusage_posix.cpp',
          ],
          'cflags!': [ '-fno-exceptions' ],
          'cflags_cc!': [ '-fno-exceptions' ]
        }],
        ['OS=="mac"', {
          'cflags+': ['-fvisibility=hidden'],
          'xcode_settings': {
            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
            'CLANG_CXX_LIBRARY': 'libc++',
            'GCC_SYMBOLS_PRIVATE_EXTERN': 'YES', # -fvisibility=hidden
          }
        }]
      ]
    }
  ]
}
