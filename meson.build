project('libpibase', 'cpp',
    default_options: [
        'cpp_std=c++23'
    ]
)

pibase_sources = [
    'src/file_ops.cpp'
]

inc = include_directories('inc')

libpibase = shared_library('libpibase',
    pibase_sources,
    include_directories : inc,
    install : true)

libpibase_dep = declare_dependency(include_directories : inc,
    link_with : libpibase)
