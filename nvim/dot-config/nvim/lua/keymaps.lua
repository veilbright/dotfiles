vim.keymap.set("n", "<Esc>", "<cmd>nohlsearch<CR>") -- clear hlsearch
vim.keymap.set("n", "<leader>q", vim.diagnostic.setloclist, { desc = "Quickfix" }) -- show quickfix

-- Switching focus between windows
vim.keymap.set("n", "<C-h>", "<C-w><C-h>", { desc = "Move focus to the left window" })
vim.keymap.set("n", "<C-l>", "<C-w><C-l>", { desc = "Move focus to the right window" })
vim.keymap.set("n", "<C-j>", "<C-w><C-j>", { desc = "Move focus to the lower window" })
vim.keymap.set("n", "<C-k>", "<C-w><C-k>", { desc = "Move focus to the upper window" })

-- Clipboard
vim.keymap.set({ "n", "v" }, "y", '"+y', { desc = "Yank to System Clipboard" })
vim.keymap.set({ "n", "v" }, "p", '"+p', { desc = "Put System Clipboard" })
vim.keymap.set({ "n", "v" }, "<leader>p", function()
	local reg1 = vim.fn.getreginfo("1")
	local reg_plus = vim.fn.getreginfo("+")
	vim.fn.setreg("1", reg_plus)
	vim.fn.setreg("+", reg1)
end, { desc = "Swaps System and Nvim Registers" })
