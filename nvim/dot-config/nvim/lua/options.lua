-- line numbers
vim.opt.number = true
vim.opt.relativenumber = true

-- visual
vim.opt.showmode = false
vim.opt.termguicolors = true
vim.opt.list = true
vim.opt.listchars = { tab = "  ", trail = "·", nbsp = "␣" }
vim.api.nvim_create_autocmd("TextYankPost", {
	callback = function()
		vim.highlight.on_yank()
	end,
})
vim.opt.pumheight = 5 -- column height for completions
vim.opt.scrolloff = 10

-- indent/tab
vim.opt.breakindent = true
vim.opt.tabstop = 4
vim.opt.softtabstop = 4
vim.opt.shiftwidth = 4

-- undo
vim.opt.undofile = true

-- search
vim.opt.ignorecase = true
vim.opt.smartcase = true
vim.opt.inccommand = "split"

-- swap
vim.opt.updatetime = 500

-- keybinds
vim.opt.timeoutlen = 300
