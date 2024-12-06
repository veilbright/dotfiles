-- line numbers
vim.opt.number = true
vim.opt.relativenumber = true

-- visual
vim.opt.showmode = false
vim.opt.list = true
vim.opt.listchars = { tab = '  ', trail = '·', nbsp = '␣' }
vim.api.nvim_create_autocmd('TextYankPost', { callback = function() vim.highlight.on_yank() end })

-- indent/tab
vim.opt.breakindent = true
vim.opt.tabstop = 4
vim.opt.shiftwidth = 4

-- undo
vim.opt.undofile = true

-- search
vim.opt.ignorecase = true
vim.opt.smartcase = true

-- swap
vim.opt.updatetime = 500

-- keybinds
vim.opt.timeoutlen = 300

-- clipboard
vim.schedule(function() vim.opt.clipboard = 'unnamedplus' end)
