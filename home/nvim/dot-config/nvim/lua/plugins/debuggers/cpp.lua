local dap = require 'dap'
-- Configure c++ specific config
-- setup cpptools adapter
dap.adapters.cppdbg = {
  id = 'cppdbg',
  type = 'executable',
  command = vim.fn.stdpath 'data' .. '/mason/bin/OpenDebugAD7',
}

-- this configuration should start cpptools and the debug the executable main in the current directory when executing :DapContinue
dap.configurations.cpp = {
  {
    name = 'Launch file',
    type = 'cppdbg',
    request = 'launch',
    program = function()
      return vim.fn.input('Path to executable: ', vim.fn.getcwd() .. '/', 'file')
    end,
    cwd = '${workspaceFolder}',
    stopAtEntry = true,
  },
  {
    name = 'Attach to gdbserver :1234',
    type = 'cppdbg',
    request = 'launch',
    MIMode = 'gdb',
    miDebuggerServerAddress = 'localhost:1234',
    miDebuggerPath = '/usr/bin/gdb',
    cwd = '${workspaceFolder}',
    program = function()
      return vim.fn.input('Path to executable: ', vim.fn.getcwd() .. '/', 'file')
    end,
  },
}
