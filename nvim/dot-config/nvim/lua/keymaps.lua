vim.keymap.set("n", "<Esc>", "<cmd>nohlsearch<CR>") -- clear hlsearch
vim.keymap.set({ "n", "v" }, "<leader>q", vim.diagnostic.setloclist, { desc = "Quickfix" }) -- show quickfix
vim.keymap.set({ "n", "v" }, "<leader>b", "gg=G<C-o>", { desc = "Tab Format" }) -- show quickfix

-- Switching focus between windows
vim.keymap.set("n", "<C-h>", "<C-w><C-h>", { desc = "Move focus to the left window" })
vim.keymap.set("n", "<C-l>", "<C-w><C-l>", { desc = "Move focus to the right window" })
vim.keymap.set("n", "<C-j>", "<C-w><C-j>", { desc = "Move focus to the lower window" })
vim.keymap.set("n", "<C-k>", "<C-w><C-k>", { desc = "Move focus to the upper window" })

-- Clipboard management
vim.keymap.set({ "n", "v" }, "d", '"1d', {})
vim.keymap.set({ "n", "v" }, "x", '"1x', {})
vim.keymap.set({ "n", "v" }, "c", '"1c', {})
vim.keymap.set({ "n", "v" }, "<leader>p", function()
	local reg1 = vim.fn.getreginfo("1")
	local reg_plus = vim.fn.getreginfo("+")
	vim.fn.setreg("1", reg_plus)
	vim.fn.setreg("+", reg1)
end, { desc = "Swaps System and Nvim Registers" })

-- Find and replace selection
vim.keymap.set({ "v", "n" }, "<leader>s", function()
	vim.api.nvim_feedkeys("*", "v", true)
	vim.api.nvim_feedkeys(":%s//", "n", true)
end, { desc = "Find and replace" })
