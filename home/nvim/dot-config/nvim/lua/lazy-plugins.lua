--  To check the current status of your plugins, run
--    :Lazy
--
--  You can press `?` in this menu for help. Use `:q` to close the window
--
--  To update plugins you can run
--    :Lazy update
--
-- NOTE: Here is where you install your plugins.
require('lazy').setup({
  'tpope/vim-sleuth', -- Detect tabstop and shiftwidth automatically

  require 'plugins.autopairs',
  require 'plugins.cmp',
  require 'plugins.conform',
  require 'plugins.gitsigns',
  require 'plugins.indent_line',
  require 'plugins.lint',
  require 'plugins.lsp-config',
  require 'plugins.mini',
  require 'plugins.neo-tree',
  require 'plugins.telescope',
  require 'plugins.todo-comments',
  require 'plugins.treesitter',
  require 'plugins.which-key',
  require 'plugins.debuggers.init',

  -- COLORSCHEMES (only load 1 at a time)
  --require 'plugins.tokyonight',
  require 'plugins.oxocarbon',
}, {
  ui = {
    -- If you are using a Nerd Font: set icons to an empty table which will use the
    -- default lazy.nvim defined Nerd Font icons, otherwise define a unicode icons table
    icons = vim.g.have_nerd_font and {} or {
      cmd = '⌘',
      config = '🛠',
      event = '📅',
      ft = '📂',
      init = '⚙',
      keys = '🗝',
      plugin = '🔌',
      runtime = '💻',
      require = '🌙',
      source = '📄',
      start = '🚀',
      task = '📌',
      lazy = '💤 ',
    },
  },
})
