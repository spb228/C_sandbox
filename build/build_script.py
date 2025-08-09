import os
import subprocess

def run_command(command, cwd=None):
    result = subprocess.run(command, shell=True, cwd=cwd)
    if (result.returncode != 0):
        raise RuntimeError("{command} failed with return code {result.returncode}")

def main():
    project_root = os.path.abspath(os.path.dirname(__file__))
    build_dir = os.path.join(project_root, 'build')
    bin_dir = os.path.join(project_root, '../bin')

    os.makedirs(build_dir, exist_ok=True)
    os.chdir(build_dir)

    cmake_confg_command = 'cmake .. -G "MinGW Makefiles"'
    cmake_build_command = 'mingw32-make'
    run_command_exe = 'c_sandbox.exe'

    run_command(cmake_confg_command)
    run_command(cmake_build_command)
    os.chdir(bin_dir)
    run_command(run_command_exe)


if __name__ == '__main__':
    main()