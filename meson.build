project('evatest', 'c', version: '1.1')

test_dep = declare_dependency(include_directories: include_directories('.'))

if get_option('TAP')
    add_project_arguments('-DEVATEST_TAP', language: 'c')
    test_works_exe = executable('evatest-test-works', 'test/test.c', dependencies: test_dep, c_args: ['-DSHOULD_WORK'])
    test_fails_exe = executable('evatest-test-fails', 'test/test.c', dependencies: test_dep)
    test('works', test_works_exe, protocol: 'tap')
    test('fails', test_fails_exe, protocol: 'tap', should_fail: true)
endif


